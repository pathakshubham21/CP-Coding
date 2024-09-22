// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

 

// Example 1:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104


class Solution {
public:


    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Solution complexity : O(log(m*n))
        int result_row = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0, r = (n*m-1);
        int mid = 0;
        while(l<=r)
        {
            mid = (l+r)/2;
            int row = mid/m;
            int col = mid%m;
            if(matrix[row][col]==target)
            {
                return true;
            }
            else if(matrix[row][col]<target)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return false;

        // Solution below Compplexity  : O(n * log(m))

        // for(int i=0;i<n;i++)
        // {
        //     if(matrix[i][m-1]==target)
        //     {
        //         return true;
        //     }
        //     else if(matrix[i][m-1]>target)
        //     {
        //         result_row = i;
        //         break;
        //     }
        // }

        // int l = 0;
        // int r = m-1;
        // int mid = 0;

        // while(l<=r)
        // {
        //     mid = (l+r)/2;
        //     if(matrix[result_row][mid]==target)
        //     {
        //         return true;
        //     }
        //     else if(matrix[result_row][mid]<target)
        //     {
        //         l = mid+1;
        //     }
        //     else
        //     {
        //         r = mid-1;
        //     }
        // }

        // return false;
        
    }
};