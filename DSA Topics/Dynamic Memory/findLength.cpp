// Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 

// Example 1:

// Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
// Output: 3
// Explanation: The repeated subarray with maximum length is [3,2,1].
// Example 2:

// Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
// Output: 5
// Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
 



class Solution {
public:

    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

    // Create a dp table to store lengths of common subarrays
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    int maxLen = 0;

    // Iterate over both arrays
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            // If elements match, increase the length of the common subarray
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLen = max(maxLen, dp[i][j]);  // Update maximum length
            }
        }
    }

    return maxLen;
        
    }
};