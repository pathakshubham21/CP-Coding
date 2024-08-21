//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
// Given an integer n, print all the n digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).

// Example 1:

// Input:
// n = 1
// Output:
// 0 1 2 3 4 5 6 7 8 9
// Explanation:
// Single digit numbers are considered to be 
// strictly increasing order.
// Example 2:

// Input:
// n = 2
// Output:
// 12 13 14 15 16 17 18 19 23....79 89
// Explanation:
// For n = 2, the correct sequence is
// 12 13 14 15 16 17 18 19 23 and so on 
// up to 89.
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function increasingNumbers() which takes an integer n as an input parameter and returns the list of numbers such that their digits are in strictly increasing order.

// Expected Time Complexity: O(9n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= n <= 9


class Solution {
  public:
  void solve(int n,vector<int>&vec,vector<int>&result)
  {
      if(n==0)
      {
          int temp = 0;
          for(int i=0;i<vec.size();i++)
          {
              temp =temp*10+vec[i];
          }
          result.push_back(temp);
          return;
      }
      
      for(int i=1;i<=9;i++)
      {
          
          if(vec.size()==0 || i>vec[vec.size()-1])
          {
              vec.push_back(i);
              solve(n-1,vec,result);
              vec.pop_back();
          }
      }
  }
    vector<int> increasingNumbers(int n) {
        vector<int>result;
        if(n==1)
        {
            for(int i=0;i<10;i++)
            {
                result.push_back(i);
            }
            return result;
        }
        vector<int>vec;
        
        solve(n,vec,result);
        return result;
    
        // Write Your Code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends