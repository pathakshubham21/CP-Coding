// Problem statement
// You are given a 2D board('N' rows and 'M' columns) of characters and a string 'word'.



// Your task is to return true if the given word exists in the grid, else return false. The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.



// Note:
// The same letter cell should not be used more than once.
// For Example:
// For a given word “design” and the given 2D board 
// [[q’, ‘v’, ‘m’, ‘h’],
//  [‘d’, ‘e’, ‘s’, ‘i’],
//  [‘d’, ‘g’, ‘f’, ‘g’],
//  [‘e’, ‘c’, ‘p’, ‘n’]]

// The word design can be formed by sequentially adjacent cells as shown by the highlighted color in the 2nd row and last column.

#include <vector>
#include <string>
using namespace std;

bool isValid(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& IsVisited, char ch, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || IsVisited[x][y] == true)
        return false;
    if (board[x][y] != ch)
        return false;

    return true;
}

void solve(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& IsVisited, string& str, int index, bool &result, int n, int m) {
    if (index == str.size()) {
        result = true;
        return;
    }

    IsVisited[x][y] = true; // Mark current cell as visited

    // UP
    if (isValid(x, y + 1, board, IsVisited, str[index], n, m)) {
        solve(x, y + 1, board, IsVisited, str, index + 1, result, n, m);
    }
    // DOWN
    if (isValid(x, y - 1, board, IsVisited, str[index], n, m)) {
        solve(x, y - 1, board, IsVisited, str, index + 1, result, n, m);
    }
    // LEFT
    if (isValid(x - 1, y, board, IsVisited, str[index], n, m)) {
        solve(x - 1, y, board, IsVisited, str, index + 1, result, n, m);
    }
    // RIGHT
    if (isValid(x + 1, y, board, IsVisited, str[index], n, m)) {
        solve(x + 1, y, board, IsVisited, str, index + 1, result, n, m);
    }

    IsVisited[x][y] = false; // Unmark the cell (backtracking)
}

bool present(vector<vector<char>>& board, string& word, int n, int m) {
    vector<vector<bool>> IsVisited(n, vector<bool>(m, false));
    bool result = false;

    // Start the search from every cell in the board
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == word[0]) {  // Start search only if first character matches
                solve(i, j, board, IsVisited, word, 1, result, n, m);
                if (result) return true;  // If the word is found, no need to search further
            }
        }
    }

    return false;
}
