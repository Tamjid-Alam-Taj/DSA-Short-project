#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

std::string makeTypo(const std::string& word) {
    if (word.length() < 2) return word;

    std::string typoWord = word;
    int pos1 = rand() % word.length();
    int pos2 = rand() % word.length();
    std::swap(typoWord[pos1], typoWord[pos2]);
    return typoWord;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    std::vector<std::string> words = {"banana", "chocolate", "programming", "funny", "typo", "kitten", "elephant", "sandwich", "penguin", "tornado"};
    int score = 0;
    int rounds = 5;

    std::cout << "Welcome to 'Catch the Typo!'\n";
    std::cout << "Spot the typo in the word and type the original word to earn points!\n";
    std::cout << "Type 'quit' to exit early.\n\n";

    for (int i = 0; i < rounds; ++i) {
        std::string originalWord = words[rand() % words.size()];
        std::string typoWord = makeTypo(originalWord);

        std::cout << "Round " << i + 1 << ": What's the correct word for '" << typoWord << "'?\n";
        std::string userAnswer;
        std::cout << "Your answer: ";
        std::cin >> userAnswer;

        if (userAnswer == "quit") {
            std::cout << "You chose to quit early.\n";
            break;
        }

        if (userAnswer == originalWord) {
            std::cout << "Correct! +10 points!\n";
            score += 10;
        } else {
            std::cout << "Oops! The correct word was '" << originalWord << "'. -5 points!\n";
            score -= 5;
        }

        std::cout << "Current score: " << score << "\n\n";
    }

    std::cout << "Game Over! Your final score is: " << score << "\n";
    std::cout << "Thanks for playing 'Catch the Typo!'\n";

    return 0;
}

