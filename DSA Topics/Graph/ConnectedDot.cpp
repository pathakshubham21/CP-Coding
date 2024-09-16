// Problem statement
// Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

// 1. These k dots are different: if i ≠ j then di is different from dj.
// 2. k is at least 4.
// 3. All dots belong to the same colour.
// 4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
// Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 2 <= N <= 1000
// 2 <= M <= 1000
// Time Limit: 1 second
// Sample Input 1:
// 3 4
// AAAA
// ABCA
// AAAA
// Sample Output 1:
// true


#include <iostream>
#include <vector>
using namespace std;

// Directions for moving to adjacent cells (up, down, left, right)
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int rows, cols;

// Function to check if the given coordinates are within the matrix bounds
bool isValid(int x, int y) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

// DFS function to detect a cycle in the board
bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, int fromX, int fromY, char color, int length) {
    visited[x][y] = true;

    // Explore all 4 directions (up, down, left, right)
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        // Check if the new coordinates are valid
        if (isValid(newX, newY) && board[newX][newY] == color) {
            // If the new cell is not the cell from which we came
            if (newX == fromX && newY == fromY) {
                continue;
            }
            // If we revisit a visited cell and the path length is >= 4, it forms a cycle
            if (visited[newX][newY]) {
                if (length >= 4) {
                    return true;
                }
            } else {
                // Continue DFS search
                if (dfs(board, visited, newX, newY, x, y, color, length + 1)) {
                    return true;
                }
            }
        }
    }

    return false;
}

// Function to check if there's a cycle on the board
bool hasCycle(vector<vector<char>>& board) {
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Traverse every cell of the board
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // If the cell hasn't been visited, start a DFS from this cell
            if (!visited[i][j]) {
                if (dfs(board, visited, i, j, -1, -1, board[i][j], 1)) {
                    return true;  // Cycle detected
                }
            }
        }
    }

    return false;  // No cycle detected
}

int main() {
    // Input the matrix dimensions
    cin >> rows >> cols;

    // Input the board
    vector<vector<char>> board(rows, vector<char>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> board[i][j];
        }
    }

    // Check if there's a cycle on the board and output the result
    if (hasCycle(board)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
