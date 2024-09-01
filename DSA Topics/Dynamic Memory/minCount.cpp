Problem statement
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.

That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1



#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& dp) {
    // Base case: if n is 0, no squares are needed
    if (n == 0) return 0;

    // If the result for n is already calculated, return it
    if (dp[n] != -1) return dp[n];

    int minCount = INT_MAX;

    // Check all squares less than or equal to n
    for (int i = 1; i * i <= n; i++) {
        minCount = min(minCount, solve(n - i * i, dp) + 1);
    }

    // Store the result in the dp array
    dp[n] = minCount;

    return minCount;
}

int minCount(int n) {
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}
