// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
 

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109





class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==1 || nums.size()==0)
        return nums.size();

        int count  = 0;
        int lastsmaller = INT_MIN;
        int longest = 1;

        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]-1 == lastsmaller)
            {
                count++;
                lastsmaller = nums[i];
            }
            else if(nums[i]!=lastsmaller)
            {
                count = 1;
                lastsmaller = nums[i];
            }

            longest = max(longest, count);
        }

        return longest;
        
    }
};