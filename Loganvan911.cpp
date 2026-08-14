#include <iostream>
#include <vector>
#include <string>

using namespace std;

void drawMaze(const vector<vector<char>>& maze, int coins, int steps) {

    system("cls");

    cout << "Controls: W (Up), A (Left), S (Down), D (Right) + Press Enter" << endl;
    cout << "Coins: " << coins << " | Steps: " << steps << endl;
    cout << "---------------------------------------" << endl;


    for (const auto& row : maze) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> maze = {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','P','.','.','.','.','#','.','.','.','.','.','#'},
        {'#','.','#','#','.','.','#','.','.','#','#','.','#'},
        {'#','.','.','.','.','#','#','.','.','.','.','.','#'},
        {'#','#','#','.','.','.','.','.','#','#','#','.','#'},
        {'#','.','.','.','#','#','.','.','.','.','.','.','#'},
        {'#','.','.','$','.','.','.','.','#','.','.','.','#'},
        {'#','.','#','#','#','#','.','.','#','.','#','E','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#'}
    };

    int playerRow = 0; 
    int playerCol;
    int coins = 0;
    int steps = 0;
    bool gameRunning = true;


    for (int i = 0; i < (int)maze.size(); i++) {
        for (int j = 0; j < (int)maze[i].size(); j++) {
            if (maze[i][j] == 'P') {
                playerRow = i;
                playerCol = j;
            }
        }
    }

    while (gameRunning) {
        drawMaze(maze, coins, steps);

        cout << "Enter move: ";
        char move;
        cin >> move;

        int newRow = playerRow;
        int newCol = playerCol;

        switch (tolower(move)) {
        case 'w': newRow--; break;
        case 's': newRow++; break;
        case 'a': newCol--; break;
        case 'd': newCol++; break;
        default: continue;
        }


        if (newRow >= 0 && newRow < (int)maze.size() &&
            newCol >= 0 && newCol < (int)maze[0].size()) {

            char target = maze[newRow][newCol];


            if (target != '#') {
                steps++;


                if (target == '$') {
                    coins++;
                }


                if (target == 'E') {
                    gameRunning = false;
                }


                maze[playerRow][playerCol] = '.';
                playerRow = newRow;
                playerCol = newCol;
                maze[playerRow][playerCol] = 'P';
            }
        }
    }

    drawMaze(maze, coins, steps);
    cout << "\n=======================================" << endl;
    cout << "Congratulations!" << endl;
    cout << "You successfully completed the maze." << endl;
    cout << "\nStatistics:" << endl;
    cout << "- Coins collected: " << coins << endl;
    cout << "- Total steps: " << steps << endl;
    cout << "=======================================" << endl;

    return 0;
}
