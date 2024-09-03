// Problem statement
// Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.

// Detailed explanation ( Input/output format, Notes, Images )
//  Constraints :
// 0 <= N <= 10^4
// 0 <= M <= 10^4

// Time Limit: 1 sec
// Sample Input 1:
// 3 3
// 1 1 0
// 1 1 1
// 1 1 1
// Sample Output 1:
// 1
// Sample Input 2:
// 4 4
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// Sample Output 2:
// 4


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int n, int m) {
    // Create a DP table to store the size of the largest square sub-matrix with all 0s ending at (i, j)
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxSquareSize = 0;
    
    // Fill the DP table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                maxSquareSize = max(maxSquareSize, dp[i][j]);
            }
        }
    }
    
    return maxSquareSize;
}
