Problem statement
// For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.

// Return 0 if the change isn't possible.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 3
// 1 2 3
// 4
// Sample Output 1 :
// 4
// Explanation to Sample Input 1 :
// Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
// Sample Input 2 :
// 6
// 1 2 3 4 5 6
// 250
// Sample Output 2 :
// 13868903


#include<vector>
int countWaysToMakeChange(int denominations[], int numDenominations, int value) {
    // DP array to store the number of ways to make change for each value from 0 to value
    vector<int> dp(value + 1, 0);
    
    // There is one way to make change for 0, which is by not using any coins
    dp[0] = 1;
    
    // Loop over each denomination
    for (int i = 0; i < numDenominations; i++) {
        // Update the dp array for all values from denominations[i] to value
        for (int j = denominations[i]; j <= value; j++) {
            dp[j] += dp[j - denominations[i]];
        }
    }
    
    // The number of ways to make change for the value
    return dp[value];
}
