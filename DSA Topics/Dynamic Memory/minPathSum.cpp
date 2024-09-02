class Solution {
public:

// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

 

// Example 1:


// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// Example 2:

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12

    int solve(vector<vector<int>>grid, int n, int m, vector<vector<int>>&dp)
    {
        if(n==1&&m==1)
        {
            return grid[0][0];
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(i!=1 || j!=1)
                {
                    dp[i][j] = min(dp[i][j-1],dp[i-1][j])+grid[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
    int minPathSum(vector<vector<int>>& grid) {

        int n= grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1, 0));

        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j] = INT_MAX;
                }
            }
        }
        dp[1][1] = grid[0][0];

        int result= solve(grid, n,m,dp);
        return result;

        
    }
};