// Problem statement
// You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.

// A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= 'N' <= 10

// Time Limit: 1sec


// For Example:
// For a chessboard of size 4*4
// The configurations are 
// alt text

// Sample Input 1:
// 4
// Sample Output 1:
// 0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
// 0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
// Explanation For Sample Input 1:
// Output depicts two possible configurations of the chessboard for 4 queens.

// The Chessboard matrix for the first configuration looks as follows:-

// 0 0 1 0
// 1 0 0 0
// 0 0 0 1
// 0 1 0 0

// Queen contained cell is depicted by 1. As seen, No queen is in the same row, column, or diagonal as the other queens. Hence this is a valid configuration.
// Sample Input 2:
// 3
// Sample Output2:
//       (Blank)
// Explanation For Sample Input 2:
// Since no possible configuration exists for 3 Queen's.The output remains Empty.


#include <vector>
#include <iostream>
using namespace std;

bool isValid(vector<vector<int>>& board, int row, int col, int n) {
    // Check the column for another queen
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check the upper left diagonal for another queen
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check the upper right diagonal for another queen
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

void solve(vector<vector<int>>& board, int row, int n, vector<vector<int>>& results) {
    // Base case: All queens are placed
    if (row == n) {
        vector<int> configuration;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                configuration.push_back(board[i][j]);
            }
        }
        results.push_back(configuration);
        return;
    }

    // Try placing the queen in every column of the current row
    for (int col = 0; col < n; col++) {
        if (isValid(board, row, col, n)) {
            board[row][col] = 1;   // Place the queen
            solve(board, row + 1, n, results);  // Recur to place the next queen
            board[row][col] = 0;   // Backtrack and remove the queen
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> results;
    solve(board, 0, n, results);
    return results;
}

