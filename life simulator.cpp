#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Player {
public:
    std::string name;
    int happiness;
    int money;
    int health;

    Player(const std::string& playerName)
        : name(playerName), happiness(50), money(100), health(50) {}

    void showStats() {
        std::cout << "\n-- Player Stats --\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Happiness: " << happiness << "/100\n";
        std::cout << "Money: $" << money << "\n";
        std::cout << "Health: " << health << "/100\n";
    }

    bool isGameOver() {
        return happiness <= 0 || health <= 0 || money <= 0;
    }
};

void showChoices() {
    std::cout << "\nChoose an action:\n";
    std::cout << "1. Work a job (earn money but lose happiness)\n";
    std::cout << "2. Exercise (improve health but lose money)\n";
    std::cout << "3. Relax (boost happiness but lose money)\n";
    std::cout << "4. Check stats\n";
}

void applyChoice(int choice, Player& player) {
    switch (choice) {
        case 1:
            player.money += 50;
            player.happiness -= 10;
            std::cout << "You worked hard and earned $50, but it's tiring.\n";
            break;
        case 2:
            player.health += 10;
            player.money -= 10;
            std::cout << "You exercised and feel healthier but spent $10 on equipment.\n";
            break;
        case 3:
            player.happiness += 15;
            player.money -= 20;
            std::cout << "You relaxed and feel happier, but relaxation costs money!\n";
            break;
        case 4:
            player.showStats();
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
    }

    if (player.happiness > 100) player.happiness = 100;
    if (player.health > 100) player.health = 100;
}

int main() {
    std::cout << "Welcome to the Life Simulator!\n";
    std::cout << "Enter your name: ";
    std::string playerName;
    std::getline(std::cin, playerName);

    Player player(playerName);

    std::cout << "Hello, " << player.name << "! Let's start the game.\n";

    while (true) {
        if (player.isGameOver()) {
            std::cout << "\nGame Over! You ran out of happiness, health, or money.\n";
            break;
        }

        showChoices();
        int choice;
        std::cin >> choice;

        applyChoice(choice, player);
    }

    return 0;
}

