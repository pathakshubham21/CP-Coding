#include <iostream>
#include <limits>
using namespace std;

int static dp[1001][1001];

int MCM_minCost(int arr[], int i, int j)
{
    if (i >= j) 
    {
        return 0;
    }

    if(dp[i][j]!=-1)
    return dp[i][j];

    int ans = INT_MAX;

    // Loop to find the optimal 'k' that minimizes the cost
    for (int k = i; k < j; k++)  // Should iterate over the valid range of 'k'
    {
        int tempans = MCM_minCost(arr, i, k) + MCM_minCost(arr, k + 1, j) + arr[i] * arr[k + 1] * arr[j];

        ans = min(ans, tempans);  // Minimize the cost
    }

    return dp[i][j]= ans;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);  // Correctly calculating the size of the array
    memset(dp, -1, sizeof(dp));
    // MCM_minCost is usually called for the entire array, i.e., from 0 to n-1
    cout << MCM_minCost(arr, 0, n - 1);  // Output the minimum cost for matrix chain multiplication
    return 0;
}
