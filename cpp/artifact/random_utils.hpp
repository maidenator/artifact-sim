#pragma once
#include <cstdint>
#include <cassert>

/**
 * Generates a random number between 0 and bound - 1
 * uses lemire's algorithm to avoid modulo bias
 * 
 * @param bound upper limit for the random number (has to be positive)
 * @param rng the xoshiro256 random engine
 */

inline uint32_t fastUniform(int32_t bound, Xoshiro256 &rng) {
    assert(bound > 0 && "Bound must be a positive integer");

    uint32_t ubound = static_cast<uint32_t>(bound);
    uint64_t x = rng();
    
    // Use 128-bit math to prevent overflow from the 64-bit rng output    
    __uint128_t m = static_cast<__uint128_t>(x) * ubound;
    uint32_t l = static_cast<uint32_t>(m);

    if (l < ubound) {
        uint32_t threshold = -ubound % ubound;
        while (l < threshold) {
            x = rng();
            m = static_cast<__uint128_t>(x) * ubound;
            l = static_cast<uint32_t>(m);
        }
    }

    return static_cast<uint32_t>(m >> 64);
}

class Xoshiro256 {
    private:
        // The 256-bit state is stored as four random 64-bit integers
        uint64_t s[4];

        // Bitwise left rotation helper
        static inline uint64_t rotateLeft(const uint64_t x, int k) {
            return (x << k) | (x >> (64 - k));
        }

        static constexpr uint64_t GOLDEN_RATIO_CONST = 0x9e3779b97f4a7c15ULL;
        static constexpr uint64_t MIXER_MULTIPLIER_1 = 0xbf58476d1ce4e5b9ULL;
        static constexpr uint64_t MIXER_MULTIPLIER_2 = 0x94d049bb133111ebULL;

    public:
        explicit Xoshiro256(uint64_t seed) {
            /*
                Mini SplitMix65 generator to expand a single seed
                into 4 healthy, non-zero state values
            */
           uint64_t z = seed + GOLDEN_RATIO_CONST;
           for(int i = 0; i < 4; ++i) {
                z = (z ^ (z >> 30)) * MIXER_MULTIPLIER_1;
                z = (z ^ (z >> 27)) * MIXER_MULTIPLIER_2;

                s[i] = z ^ (z >> 31);
           } 
        }

        inline uint64_t operator() () {
            // 1. Generate the output value by mixing state elements
            const uint64_t result = rotateLeft(s[1]  * 5, 7) * 9;

            // 2. Shift and scramble the 256 bit vector
            const uint64_t t = s[1] << 17;

            s[2] ^= s[0];
            s[3] ^= s[1];
            s[1] ^= s[2];
            s[0] ^= s[3];

            s[2] ^= t;
            s[3] = rotateLeft(s[3], 45);

            return result;
        }
};