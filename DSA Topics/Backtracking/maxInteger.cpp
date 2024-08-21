//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    
    void solve(string &num, string &result, int start, int k) {
        // Base case: if no swaps left or reached the end of the string
        if (k == 0 || start == num.length()) {
            return;
        }

        // Find the maximum character from start+1 onwards
        char maxChar = *std::max_element(num.begin() + start, num.end());

        // If maxChar is equal to the current character, skip it
        if (maxChar != num[start]) {
            // Explore all positions where maxChar exists
            for (int i = start + 1; i < num.length(); i++) {
                if (num[i] == maxChar) {
                    // Swap num[start] with num[i]
                    swap(num[start], num[i]);

                    // Update result if current permutation is larger
                    if (num.compare(result) > 0) {
                        result = num;
                    }

                    // Recur for the next position with one less swap
                    solve(num, result, start + 1, k - 1);

                    // Backtrack to try other swaps
                    swap(num[start], num[i]);
                }
            }
        } else {
            // If maxChar is already in the correct place, move to the next character
            solve(num, result, start + 1, k);
        }
    }

    string findMaximumNum(string num, int k) {
        string result = num;
        solve(num, result, 0, k);
        return result;
    }

};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends