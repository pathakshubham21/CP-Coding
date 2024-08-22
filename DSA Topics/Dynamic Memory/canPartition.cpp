
// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
 

// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100
    bool solve(vector<int>&nums, int n, int HalfSum)
    {
        bool dp[n+1][HalfSum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<HalfSum+1;j++)
            {
                if(i==0)
                dp[i][j] = false;
                if(j==0)
                dp[i][j] = true;
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<HalfSum+1;j++)
            {
                if(nums[i-1]<=j)
                {
                dp[i][j] = dp[i-1][j-nums[i-1]]|| dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][HalfSum];
    }
    bool canPartition(vector<int>& nums) {

        int sum= 0;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1)
        return false;
        sum= sum/2;

        return solve(nums,n,sum);

        
    }