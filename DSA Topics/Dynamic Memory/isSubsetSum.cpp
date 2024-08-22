//  Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 


// Example 1:

// Input:
// N = 6
// arr[] = {3, 34, 4, 12, 5, 2}
// sum = 9
// Output: 1 
// Explanation: Here there exists a subset with
// sum = 9, 4+3+2 = 9.
// Example 2:

// Input:
// N = 6
// arr[] = {3, 34, 4, 12, 5, 2}
// sum = 30
// Output: 0 
// Explanation: There is no subset with sum 30.
 
 // Recursive solution 
 bool solve(vector<int>&arr,int sum , int sumTillNow, int n)
 {
     if(sum==0)
     return true;
     if(n==0)
     return false;
     
     if(sumTillNow == sum)
     return true;
     
     if(arr[n-1]<=sum)
     {
         return solve(arr,sum, sumTillNow+arr[n-1],n-1) || solve(arr, sum , sumTillNow, n-1);
     }
     else
     {
         return solve(arr, sum , sumTillNow, n-1);
     }
 }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        return solve(arr, sum, 0, arr.size());
    }








// memoization solution 
bool solve(vector<int>& arr, int sum, int n, vector<vector<int>>& m) {
    if (sum == 0) return true;
    if (n == 0) return false;

    // Check if the value is already computed
    if (m[n][sum] != -1) {
        return m[n][sum];
    }

    if (arr[n - 1] <= sum) {
        // Include or exclude the current element
        return m[n][sum] = solve(arr, sum - arr[n - 1], n - 1, m) || solve(arr, sum, n - 1, m);
    } else {
        // Exclude the current element
        return m[n][sum] = solve(arr, sum, n - 1, m);
    }

}

bool isSubsetSum(vector<int> arr, int sum) {
    int n = arr.size();

    // Initialize memoization table with -1 (which means unvisited)
    vector<vector<int>> m(n + 1, vector<int>(sum + 1, -1));

    // Solve the problem
    return solve(arr, sum, n, m);
}

// DP solution   
bool isSubsetSum(vector<int>arr, int sum){
        int n= arr.size();
        bool dp[n+1][sum+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                {
                    dp[i][j] = false;
                }
                if(j==0)
                {
                    dp[i][j] = true;
                }
            }
        }
            
         for(int i=1;i<n+1;i++)
            {
                for(int j=1;j<sum+1;j++)
                {
                    
                    if(arr[i-1]<=j)
                    {
                        dp[i][j] = dp[i-1][j-arr[i-1]]|| dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
            
        }
    }
    return dp[n][sum];
        }