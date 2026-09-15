#include <iostream>
#include <random>
#include <format>
#include "generator.hpp"
#include "format_utils.hpp"

// Function to clear the console using ANSI escape codes
void clearConsole() {
    std::cout << "\033[2J\033[1;1H";
}

// Helper function to cleanly print artifact details
#include <format> // Required for std::format

void printArtifact(const Artifact &art) {
    std::cout << "----------------------------------------\n";
    std::cout << "ID: " << *art.id << "\n";
    std::cout << "Slot: " << art.slot << "\n";
    std::cout << "Level: +" << art.level << "\n";
    
    // Format main stat value to 1 decimal place (e.g., ATK%: +46.6)
    std::cout << "Main Stat: " << art.mainStat.type  
              << " | Value: +" << std::format("{:.1f}", art.mainStat.value) << "\n";
    
    std::cout << "Substats (" << art.substatCount << "):\n";
    
    for (int i = 0; i < art.substatCount; ++i) {    
        // Format substat value to 1 decimal place (e.g., Crit Rate: +7.0)
        std::cout << "  - " << art.subStats[i].type
                  << ": +" << std::format("{:.1f}", art.subStats[i].value) << "\n";
    }
    std::cout << "----------------------------------------\n";
    
    // Optional: Format Crit Value nicely too
    std::cout << "Crit Value: " << std::format("{:.1f}", generator::calculateCritValue(art)) << "\n";
}

int main() {
    std::random_device rd;
    rng::Xoshiro256 rng(rd());

    Artifact currentArtifact{};
    bool hasArtifact = false;

    clearConsole();
    std::cout << "=== Artifact Generator & Upgrader Test ===" << std::endl;
    std::cout << "Controls:\n";
    std::cout << "  [g] Generate a new artifact\n";
    std::cout << "  [u] Upgrade current artifact (+4 levels)\n";
    std::cout << "  [q] Quit\n\n";
    std::cout << "Enter command: ";

    char input = '\0';
    while (std::cin >> input) {
        if (input == 'q' || input == 'Q') {
            break;
        }

        if (input == 'g' || input == 'G') {
            currentArtifact = generator::generateArtifact(rng);
            hasArtifact = true;

            clearConsole();
            std::cout << "[Action: Generated New Artifact]\n\n";
            printArtifact(currentArtifact);
        }
        else if (input == 'u' || input == 'U') {
            clearConsole();
            if (!hasArtifact) {
                std::cout << "[Action Failed: No active artifact to upgrade. Press 'g' first!]\n\n";
            } 
            else if (currentArtifact.level >= 20) {
                std::cout << "[Action Failed: Artifact is already at maximum level (+20)!]\n\n";
                printArtifact(currentArtifact);
            } 
            else {
                generator::upgradeArtifactOnce(currentArtifact, rng);
                std::cout << "[Action: Upgraded Artifact to Level +" << currentArtifact.level << "]\n\n";
                printArtifact(currentArtifact);
            }
        }

        std::cout << "\nCommands -> [g] Generate | [u] Upgrade | [q] Quit: ";
    }

    return 0;
}