#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    string choices[] = {"Rock", "Paper", "Scissors"};
    int userChoice, computerChoice;

    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "1. Rock\n2. Paper\n3. Scissors" << endl;

    cout << "Enter your choice (1-3): ";
    cin >> userChoice;

    if (userChoice < 1 || userChoice > 3) {
        cout << "Invalid choice! Exiting game." << endl;
        return 1;
    }

    computerChoice = rand() % 3 + 1;

    cout << "You chose: " << choices[userChoice - 1] << endl;
    cout << "Computer chose: " << choices[computerChoice - 1] << endl;

    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((userChoice == 1 && computerChoice == 3) ||
               (userChoice == 2 && computerChoice == 1) ||
               (userChoice == 3 && computerChoice == 2)) {
        cout << "You win!" << endl;
    } else {
        cout << "You lose!" << endl;
    }

    return 0;
}

