// Given an array nums of distinct integers, return all the possible 
// permutations
// . You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10

    void Helper(vector<int>nums, vector<vector<int>>&result, int index)
    {
        if(index==nums.size()-1)
        {
            result.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
        swap(nums[index],nums[i]);
        Helper(nums, result, index+1);
        swap(nums[index],nums[i]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>result;
        // if(nums.size()==1)
        // {
        //     result.push_back(nums);
        //     return result;
        // }
        Helper(nums,result, 0);
        return result;


        
        
    }