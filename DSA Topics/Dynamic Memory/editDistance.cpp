// Problem statement
// You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.

// Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:

// 1. Delete a character
// 2. Replace a character with another one
// 3. Insert a character
// Note :
// Strings don't contain spaces in between.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= M <= 10 ^ 3
// 0 <= N <= 10 ^ 3

// Time Limit: 1 sec
// Sample Input 1 :
// abc
// dc
// Sample Output 1 :
// 2
//  Explanation to the Sample Input 1 :
//  In 2 operations we can make string T to look like string S.
// First, insert character 'a' to string T, which makes it "adc".

// And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 

// Hence, the minimum distance.
// Sample Input 2 :
// whgtdwhgtdg
// aswcfg
// Sample Output 2 :
// 9


#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solve(string &s1, string &s2, int index1, int index2, vector<vector<int>> &dp) {
    // Base cases
    if (index1 == s1.length()) {
        return s2.length() - index2; // Insert all remaining characters of s2
    }
    if (index2 == s2.length()) {
        return s1.length() - index1; // Delete all remaining characters of s1
    }

    // If already calculated, return the stored value
    if (dp[index1][index2] != -1) {
        return dp[index1][index2];
    }

    // If characters match, move to the next pair of characters
    if (s1[index1] == s2[index2]) {
        dp[index1][index2] = solve(s1, s2, index1 + 1, index2 + 1, dp);
    } else {
        // Three possible operations:
        int insertOp = 1 + solve(s1, s2, index1, index2 + 1, dp);
        int deleteOp = 1 + solve(s1, s2, index1 + 1, index2, dp);
        int replaceOp = 1 + solve(s1, s2, index1 + 1, index2 + 1, dp);

        dp[index1][index2] = min(insertOp, min(deleteOp, replaceOp));
    }

    return dp[index1][index2];
}

int editDistance(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a 2D vector initialized with -1
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return solve(s1, s2, 0, 0, dp);
}
