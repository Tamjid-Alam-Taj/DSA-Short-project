#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int userGuess = 0;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100. Can you guess what it is?" << endl;

    while (userGuess != secretNumber) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (userGuess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts!" << endl;
        }
    }

    return 0;
}
