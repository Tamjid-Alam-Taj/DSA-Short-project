#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

void displayTrafficLight(const string &color) {
    if (color == "Red") {
        cout << "  Red Light! Stop!\n";
    } else if (color == "Yellow") {
        cout << "  Yellow Light! Slow Down!\n";
    } else if (color == "Green") {
        cout << "  Green Light! Go!\n";
    }
}

string getTrafficLightColor() {
    int random = rand() % 3;
    if (random == 0) return "Red";
    if (random == 1) return "Yellow";
    return "Green";
}

int main() {
    srand(time(0));
    int score = 0;
    int attempts = 5;

    cout << "Welcome to the Traffic Light Game!\n";
    cout << "Follow the traffic rules to score points.\n\n";

    while (attempts--) {
        string trafficLight = getTrafficLightColor();
        displayTrafficLight(trafficLight);

        cout << "What should you do? (Go/Stop/Slow): ";
        string playerAction;
        cin >> playerAction;

        for (auto &c : playerAction) c = tolower(c);

        if ((trafficLight == "Red" && playerAction == "stop") ||
            (trafficLight == "Yellow" && playerAction == "slow") ||
            (trafficLight == "Green" && playerAction == "go")) {
            cout << "Correct action! You earned a point!\n";
            score++;
        } else {
            cout << "Wrong action! Be careful.\n";
        }

        cout << "Your current score: " << score << "\n\n";
        this_thread::sleep_for(chrono::seconds(2));
    }

    cout << "Game Over! Your total score is: " << score << "/5\n";

    if (score == 5) {
        cout << "Excellent! You're a traffic rules expert!\n";
    } else if (score >= 3) {
        cout << "Good job! But remember to always follow the rules.\n";
    } else {
        cout << "You need more practice. Stay safe on the road!\n";
    }

    return 0;
}

