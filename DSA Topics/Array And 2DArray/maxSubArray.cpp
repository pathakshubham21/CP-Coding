// Given an integer array nums, find the 
// subarray
//  with the largest sum, and return its sum.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104


class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currentSum = 0;
        int resultSum = -1;
        int minValue= INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>minValue)
            {
                minValue = nums[i];
            }
            currentSum+=nums[i];
            if(currentSum>resultSum)
            {
                resultSum = currentSum;
            }
            if(currentSum<0)
            {
                currentSum =0;
            }
        }
        if(resultSum == -1)
        {
            return minValue;
        }

        return resultSum;
        
    }
};