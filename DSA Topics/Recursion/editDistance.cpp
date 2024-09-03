// Problem statement
// Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.

// Edit Distance
// Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
// 1. Delete a character
// 2. Replace a character with another one
// 3. Insert a character
// Note
// Strings don't contain spaces
// You need to find the edit distance from input string1 to input string2.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1<= m,n <= 10
// Time Limit: 1 second
// Sample Input 1 :
// abc
// dc
// Sample Output 1 :
// 2


int solve(string s1, string s2, int index1, int index2) {
    // Base cases
    if (index1 == s1.length()) {
        return s2.length() - index2; // Insert all remaining characters of s2
    }
    if (index2 == s2.length()) {
        return s1.length() - index1; // Delete all remaining characters of s1
    }

    // If characters match, move to the next pair of characters
    if (s1[index1] == s2[index2]) {
        return solve(s1, s2, index1 + 1, index2 + 1);
    } else {
        // Three possible operations:
        // Insert: Solve for (index1, index2 + 1)
        int insertOp = 1 + solve(s1, s2, index1, index2 + 1);

        // Delete: Solve for (index1 + 1, index2)
        int deleteOp = 1 + solve(s1, s2, index1 + 1, index2);

        // Replace: Solve for (index1 + 1, index2 + 1)
        int replaceOp = 1 + solve(s1, s2, index1 + 1, index2 + 1);

        return min(insertOp, min(deleteOp, replaceOp));
    }
}

int editDistance(string s1, string s2) {
    return solve(s1, s2, 0, 0);
}
