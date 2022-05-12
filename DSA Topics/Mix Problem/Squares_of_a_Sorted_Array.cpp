class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int left=0, right=n-1;
        vector<int> ans;
        
        while(left<=right){
            if(abs(nums[right]) >= abs(nums[left])){
                ans.push_back(pow(nums[right], 2));
                right--;
            }
            else{
                ans.push_back(pow(nums[left], 2));
                left++;
            }
        }
        reverse(ans.begin(), ans.end());  // O(n)
        
        return ans;
    }
};
