// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.


// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.



class Solution {
public:
    void sortColors(vector<int>& nums) {

        int ZeroCount = 0;
        int OneCount = 0;
        int TwoCount = 0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                ZeroCount++;
            }
            else if( nums[i]==1)
            {
                OneCount++;
            }
            else 
            {
                TwoCount++;
            }
        }

        for(int i=0;i<nums.size();i++)
        {
            if(ZeroCount>0)
            {
                nums[i] = 0;
                ZeroCount--;
            }
            else if(OneCount>0)
            {
                nums[i] =1;
                OneCount--;
            }
            else 
            {
                nums[i] =2;
            }
        }
        
        
    }
 //approach = Dutch National Flag Algorithm
    void sortColors(vector<int>& nums) {
        int low =0, mid =0;
        int high = nums.size()-1;

        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }

    }
};