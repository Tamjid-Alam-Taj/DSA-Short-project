#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int WIDTH = 10;
const int HEIGHT = 10;

struct Player {
    int x, y;
    int lives;
    int treasures;
};

void initializeMaze(vector<vector<char>> &maze) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            maze[i][j] = '.';
        }
    }
    srand(time(0));
    for (int i = 0; i < WIDTH; i++) {
        maze[rand() % HEIGHT][rand() % WIDTH] = 'T';
        maze[rand() % HEIGHT][rand() % WIDTH] = '$';
    }
    maze[rand() % HEIGHT][rand() % WIDTH] = 'E';
}

void printMaze(vector<vector<char>> &maze, Player &player) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == player.y && j == player.x) {
                cout << 'P';
            } else {
                cout << maze[i][j];
            }
        }
        cout << endl;
    }
}

bool movePlayer(Player &player, char direction, vector<vector<char>> &maze) {
    int newX = player.x;
    int newY = player.y;

    switch (direction) {
        case 'w': newY--; break;
        case 's': newY++; break;
        case 'a': newX--; break;
        case 'd': newX++; break;
        default: return false;
    }

    if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT) {
        cout << "You hit a wall!\n";
        return false;
    }

    player.x = newX;
    player.y = newY;

    char currentTile = maze[player.y][player.x];

    if (currentTile == 'T') {
        player.lives--;
        cout << "You stepped on a trap! Lives remaining: " << player.lives << endl;
        maze[player.y][player.x] = '.';
    } else if (currentTile == '$') {
        player.treasures++;
        cout << "You found a treasure! Treasures collected: " << player.treasures << endl;
        maze[player.y][player.x] = '.';
    } else if (currentTile == 'E') {
        cout << "Congratulations! You found the exit with " << player.treasures << " treasures!\n";
        return true;
    }
    return false;
}

int main() {
    vector<vector<char>> maze(HEIGHT, vector<char>(WIDTH));
    initializeMaze(maze);

    Player player = {0, 0, 3, 0};

    cout << "Welcome to the Maze Adventure Game!\n";
    cout << "Controls: w (up), s (down), a (left), d (right)\n";
    cout << "Find the exit (E) while collecting treasures ($) and avoiding traps (T).\n\n";

    bool gameRunning = true;
    while (gameRunning && player.lives > 0) {
        printMaze(maze, player);
        cout << "Enter your move: ";
        char move;
        cin >> move;
        if (movePlayer(player, move, maze)) {
            gameRunning = false;
        }
    }

    if (player.lives <= 0) {
        cout << "Game Over! You lost all your lives.\n";
    }

    return 0;
}

