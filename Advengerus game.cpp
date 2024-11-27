#include <iostream>
#include <string>

using namespace std;

void intro() {
    cout << "Welcome to the Adventure Game!" << endl;
    cout << "You find yourself at the entrance of a dark cave. What do you do?" << endl;
    cout << "1. Enter the cave" << endl;
    cout << "2. Walk away" << endl;
}

void enterCave() {
    cout << "\nYou step into the cave. It's dark and cold." << endl;
    cout << "You hear strange noises. What do you do?" << endl;
    cout << "1. Light a torch" << endl;
    cout << "2. Walk forward in the dark" << endl;
}

void lightTorch() {
    cout << "\nYou light a torch. The cave is illuminated." << endl;
    cout << "You see a treasure chest in the corner and a sleeping dragon nearby. What do you do?" << endl;
    cout << "1. Open the chest" << endl;
    cout << "2. Sneak past the dragon" << endl;
}

void openChest() {
    cout << "\nYou quietly open the chest and find a pile of gold!" << endl;
    cout << "Congratulations! You've completed the adventure and found the treasure." << endl;
}

void sneakPastDragon() {
    cout << "\nYou try to sneak past the dragon, but it wakes up!" << endl;
    cout << "The dragon roars and breathes fire. You barely escape with your life." << endl;
    cout << "Game Over." << endl;
}

void walkInDark() {
    cout << "\nYou stumble in the dark and fall into a pit!" << endl;
    cout << "Game Over." << endl;
}

void walkAway() {
    cout << "\nYou walk away from the cave, missing out on the adventure." << endl;
    cout << "Maybe next time you'll be braver!" << endl;
    cout << "Game Over." << endl;
}

int main() {
    int choice;

    intro();
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        enterCave();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            lightTorch();
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                openChest();
            } else if (choice == 2) {
                sneakPastDragon();
            }
        } else if (choice == 2) {
            walkInDark();
        }

    } else if (choice == 2) {
        walkAway();
    }

    return 0;
}

