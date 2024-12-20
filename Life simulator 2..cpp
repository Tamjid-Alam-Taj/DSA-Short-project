
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayStats(int energy, int knowledge, int socialLife) {
    cout << "\nYour Current Stats:\n";
    cout << "Energy: " << energy << endl;
    cout << "Knowledge: " << knowledge << endl;
    cout << "Social Life: " << socialLife << endl;
}

int main() {
    int energy = 100;
    int knowledge = 100;
    int socialLife = 100;

    srand(static_cast<unsigned>(time(0)));

    cout << "Welcome to the College Life Simulation Game!\n";
    cout << "Your goal is to balance your Energy, Knowledge, and Social Life.\n";
    cout << "Make wise choices to graduate successfully!\n";

    int day = 1;
    while (energy > 0 && knowledge > 0 && socialLife > 0) {
        cout << "\n---- Day " << day << " ----\n";

        int event = rand() % 3;
        switch (event) {
            case 0:
                cout << "You have an important assignment due tomorrow.\n";
                cout << "1. Pull an all-nighter to complete it (-30 Energy, +50 Knowledge)\n";
                cout << "2. Skip it (-20 Knowledge)\n";
                break;
            case 1:
                cout << "Your friends invite you to a party.\n";
                cout << "1. Attend the party (-20 Energy, +30 Social Life)\n";
                cout << "2. Stay in and study (+20 Knowledge, -10 Social Life)\n";
                break;
            case 2:
                cout << "You have the opportunity to join a study group.\n";
                cout << "1. Join the group (-10 Social Life, +30 Knowledge)\n";
                cout << "2. Decline and relax (+20 Energy, no change in others)\n";
                break;
        }

        int choice;
        cout << "Choose an option (1 or 2): ";
        cin >> choice;

        if (event == 0 && choice == 1) {
            energy -= 30;
            knowledge += 50;
        } else if (event == 0 && choice == 2) {
            knowledge -= 20;
        } else if (event == 1 && choice == 1) {
            energy -= 20;
            socialLife += 30;
        } else if (event == 1 && choice == 2) {
            knowledge += 20;
            socialLife -= 10;
        } else if (event == 2 && choice == 1) {
            socialLife -= 10;
            knowledge += 30;
        } else if (event == 2 && choice == 2) {
            energy += 20;
        }

        displayStats(energy, knowledge, socialLife);

        day++;
    }

    cout << "\nGame Over!\n";
    if (energy <= 0) {
        cout << "You ran out of energy.\n";
    }
    if (knowledge <= 0) {
        cout << "Your knowledge reached zero.\n";
    }
    if (socialLife <= 0) {
        cout << "Your social life reached zero.\n";
    }
    cout << "You survived for " << day - 1 << " days.\n";

    return 0;
}
