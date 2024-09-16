// Problem statement
// Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .

// There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= N <= 1000
// 1 <= M <= 1000
// Time Limit: 1 second
// Sample Input 1:
// 2 11
// CXDXNXNXNXA
// XOXIXGXIXJX
// Sample Output 1:
// 1

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const string TARGET = "CODINGNINJA";  // The target string we're looking for
int rows, cols;

// Directions for moving to the 8 possible neighboring cells (up, down, left, right, and the 4 diagonals)
int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

// Function to check if the given coordinates are within the matrix bounds
bool isValid(int x, int y) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

// DFS function to search for the target word
bool dfs(vector<vector<char>>& matrix, vector<vector<bool>>& visited, int x, int y, int index) {
    // If we have matched the entire target word, return true
    if (index == TARGET.size()) {
        return true;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Explore all 8 possible directions
    for (int i = 0; i < 8; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        // Check if the new coordinates are valid and if the next character matches
        if (isValid(newX, newY) && !visited[newX][newY] && matrix[newX][newY] == TARGET[index]) {
            // Recursively call DFS for the next character in the target word
            if (dfs(matrix, visited, newX, newY, index + 1)) {
                return true;
            }
        }
    }

    // Backtrack: unmark the current cell as visited
    visited[x][y] = false;
    return false;
}

// Function to check if the word "CODINGNINJA" can be found in the matrix
bool findCodingNinja(vector<vector<char>>& matrix) {
    // Create a visited matrix to track the cells we've already explored
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Start DFS from any cell that contains 'C', the first character of the target word
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 'C') {
                // Start DFS from this cell
                if (dfs(matrix, visited, i, j, 1)) {  // index 1 since 'C' is already matched
                    return true;
                }
            }
        }
    }

    return false;  // No valid path found
}

int main() {
    // Input the matrix dimensions
    cin >> rows >> cols;

    // Input the matrix
    vector<vector<char>> matrix(rows, vector<char>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Check if "CODINGNINJA" can be found in the matrix
    if (findCodingNinja(matrix)) {
        cout << 1 << endl;  // Found
    } else {
        cout << 0 << endl;  // Not found
    }

    return 0;
}
