#include <iostream>
#include <random>
#include "generator.hpp"
#include "format_utils.hpp"

int main() {
    std::random_device rd;
    rng::Xoshiro256 rng(rd());

    std::cout << "=== Artifact Generator Test ===" << std::endl;
    std::cout << "Type 'g' and press Enter to generate an artifact (or 'q' to quit):\n\n";

    char input = '\0';
    while (std::cin >> input) {
        if (input == 'q' || input == 'Q') {
            break;
        }

        if (input == 'g' || input == 'G') {
            Artifact art = generator::generateArtifact(rng);
            std::cout << "\n----------------------------------------\n";
            std::cout << "ID: " << *art.id << "\n";
            std::cout << "Slot: " << static_cast<int>(art.slot) << "\n";
            std::cout << "Main Stat Type: " << static_cast<int>(art.mainStat.type) 
                      << " | Value: " << art.mainStat.value << "\n";
            std::cout << "Substats (" << art.substatCount << "):\n";
            
            for (int i = 0; i < art.substatCount; ++i) {
                std::cout << "  - Stat " << format_utils::substatToString(art.subStats[i].type)
                          << ": +" << art.subStats[i].value << "\n";
            }
            std::cout << "----------------------------------------\n\n";
        }

        std::cout << "Press 'g' for another, or 'q' to quit: ";
    }

    return 0;
}