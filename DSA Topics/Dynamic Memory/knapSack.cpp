//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// You are given weights and values of N items, and put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum sum values subset of val[] such that the sum of the weights of the corresponding subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don't pick it (0-1 property).

// Examples :

// Input: W = 4, val[] = {1,2,3}, wt[] = {4,5,1}
// Output: 3
// Explanation: Choose the last item that weighs 1 unit and holds a value of 3. 
// Input: W = 3, val[] = {1,2,3}, wt[] = {4,5,6}
// Output: 0
// Explanation: Every item has a weight exceeding the knapsack's capacity (3).

  int solve(int W, vector<int>& wt, vector<int>& val,int n)
  {
      if(W==0 || n==0)
      {
          return 0;
      }
      if(wt[n-1]<=W)
      {
          return max(val[n-1]+solve(W-wt[n-1],wt,val,n-1),solve(W,wt,val,n-1));
      }
      else
      {
          return solve(W,wt,val,n-1);
      }
  }
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        return solve(W,wt,val,wt.size());
        
    }

// Solution using memoization 
static int t[1001][1001];

    int solve(int W, vector<int>& wt, vector<int>& val, int n) {
        if (W == 0 || n == 0) {
            return 0;
        }

        if (t[n][W] != -1) {
            return t[n][W];
        }

        if (wt[n - 1] <= W) {
            return t[n][W] = max(val[n - 1] + solve(W - wt[n - 1], wt, val, n - 1), solve(W, wt, val, n - 1));
        } else {
            return t[n][W] = solve(W, wt, val, n - 1);
        }
    }

    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        memset(t, -1, sizeof(t));  // Initialize memoization table with -1
        return solve(W, wt, val, wt.size());
    }
