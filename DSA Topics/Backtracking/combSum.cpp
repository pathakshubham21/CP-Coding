// Problem statement
// You are given an array 'ARR' of 'N' distinct positive integers. You are also given a non-negative integer 'B'.



// Your task is to return all unique combinations in the array whose sum equals 'B'. A number can be chosen any number of times from the array 'ARR'.



// Elements in each combination must be in non-decreasing order.



// For example:
// Let the array 'ARR' be [1, 2, 3] and 'B' = 5. Then all possible valid combinations are-

// (1, 1, 1, 1, 1)
// (1, 1, 1, 2)
// (1, 1, 3)
// (1, 2, 2)
// (2, 3)
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 3 8
// 2 3 5
// Sample Output 1:
// Yes
// Explanation Of Sample Input 1 :
// All possible valid combinations are:
// 2 2 2 2
// 2 3 3
// 3 5
// Sample Input 2 :
// 3 5
// 1 2 3 
// Sample Output 2:
// Yes
// Constraints:
// 1 <= 'N' <= 15
// 1 <= 'B' <= 20
// 1 <= 'ARR[i]' <= 20

// Time Limit: 1sec

void solve(vector<int>& arr, vector<vector<int>>& result, int B, vector<int>& inter, int index) {
    // Base case: if B is zero, we found a valid combination
    if (B == 0) {
        result.push_back(inter);
        return;
    }

    // Loop through the array elements starting from the current index
    for (int i = index; i < arr.size(); i++) {
        // If the current element is less than or equal to B, it can be part of the combination
        if (arr[i] <= B) {
            inter.push_back(arr[i]);
            // Recur with reduced B and same index i (since elements can be reused)
            solve(arr, result, B - arr[i], inter, i);
            // Backtrack: remove the last element added
            inter.pop_back();
        }
    }
}

vector<vector<int>> combSum(vector<int>& arr, int B) {
    vector<vector<int>> result;
    vector<int> inter;

    // Sort the array to ensure combinations are in non-decreasing order
    sort(arr.begin(), arr.end());
    
    // Call the recursive function to find all combinations
    solve(arr, result, B, inter, 0);

    return result;
}
