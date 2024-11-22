#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playGame() {
    int playerRoll, computerRoll;
    int playerScore = 0, computerScore = 0;
    int rounds;
    char playAgain;

    srand(static_cast<unsigned int>(time(0)));

    cout << "Welcome to the Dice Game!" << endl;
    cout << "Enter the number of rounds you want to play: ";
    cin >> rounds;

    for (int round = 1; round <= rounds; ++round) {
        cout << "\nRound " << round << "!" << endl;

        playerRoll = rand() % 6 + 1;
        cout << "You rolled: " << playerRoll << endl;

        computerRoll = rand() % 6 + 1;
        cout << "Computer rolled: " << computerRoll << endl;

        if (playerRoll > computerRoll) {
            cout << "You win this round!" << endl;
            ++playerScore;
        } else if (computerRoll > playerRoll) {
            cout << "Computer wins this round!" << endl;
            ++computerScore;
        } else {
            cout << "It's a tie this round!" << endl;
        }
    }

    cout << "\nGame Over!" << endl;
    cout << "Final Scores:" << endl;
    cout << "You: " << playerScore << endl;
    cout << "Computer: " << computerScore << endl;

    if (playerScore > computerScore) {
        cout << "Congratulations! You are the overall winner!" << endl;
    } else if (computerScore > playerScore) {
        cout << "The computer wins this time. Better luck next time!" << endl;
    } else {
        cout << "It's an overall tie!" << endl;
    }

    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        playGame();
    } else {
        cout << "Thanks for playing! Goodbye!" << endl;
    }
}

int main() {
    playGame();
    return 0;
}

