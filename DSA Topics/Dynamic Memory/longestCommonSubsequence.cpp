// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

 

// Example 1:

// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.

class Solution {
public:
    int solve(string &s1, string &s2, int n1, int n2, vector<vector<int>> &dp) {
    // Base case: if either string is empty, LCS is 0
    if (n1 == 0 || n2 == 0) {
        return 0;
    }
    
    // Check if result is already computed
    if (dp[n1][n2] != -1) {
        return dp[n1][n2];
    }
    
    // Case 1: Characters match, include the character in LCS and move both indices back
    if (s1[n1-1] == s2[n2-1]) {
        dp[n1][n2] = 1 + solve(s1, s2, n1 - 1, n2 - 1, dp);
    } 
    // Case 2: Characters don't match, explore both possibilities
    else {
        dp[n1][n2] = max(solve(s1, s2, n1 - 1, n2, dp), solve(s1, s2, n1, n2 - 1, dp));
    }
    
    return dp[n1][n2];
}

int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.length();
    int n2 = text2.length();
    
    // Initialize dp array with -1 (to mark uncomputed values)
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
    
    // Call the recursive function
    return solve(text1, text2, n1, n2, dp);
}

};