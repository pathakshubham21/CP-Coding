// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

// Example 1:


// Input: m = 3, n = 7
// Output: 28
// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down



int helper(int m, int n, int i, int j, vector<vector<int>>& dp) {
    // Base case: If robot reaches the bottom-right corner
    if (i == m - 1 && j == n - 1) {
        return 1;
    }
    
    // If robot goes out of bounds, return 0
    if (i >= m || j >= n) {
        return 0;
    }

    // If the value is already computed, return it
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    // Recursive case: move down or right
    int ans = helper(m, n, i + 1, j, dp) + helper(m, n, i, j + 1, dp);

    // Store the computed result in dp array
    dp[i][j] = ans;

    return ans;
}

int uniquePaths(int m, int n) {
    // Initialize dp array with -1 to signify uncomputed values
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // Start the recursion from the top-left corner (0, 0)
    return helper(m, n, 0, 0, dp);
}