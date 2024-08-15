// Problem statement
// You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.

// You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.

// Note:
// 1. Best solution takes O(n) time.
// 2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= n <= 10^6
// Time Limit: 1 sec
// Sample Input 1 :
// 13
// 2 12 9 16 10 5 3 20 25 11 1 8 6 
// Sample Output 1 :
// 8 12 
// Explanation:The longest consecutive sequence here is [8, 9, 10, 11, 12]. So the output is the start and end of this sequence: [8, 12].
// Sample Input 2 :
// 7
// 3 7 2 1 9 8 41
// Sample Output 2 :
// 7 9
// Explanation:There are two sequences of equal length here: [1,2,3] and [7,8,9]. But since [7,8,9] appears first in the array (7 comes before 1), we return this sequence. So the output is [7,9].
// Sample Input 3 :
// 7
// 15 24 23 12 19 11 16
// Sample Output 3 :
// 15 16
// Explanation:The longest consecutive sequence here is [15,16]. So the output is [15,16].

#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_set<int> numSet(arr, arr + n);  // Store all elements in a hash set
    int maxLength = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        int num = arr[i];

        // Check if current number is the start of a sequence
        if (numSet.find(num - 1) == numSet.end()) {
            int currentLength = 1;
            int currentStart = num;

            // Extend the sequence
            while (numSet.find(num + currentLength) != numSet.end()) {
                currentLength++;
            }

            // Update the maximum sequence length and starting point
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = currentStart;
            }
        }
    }

    // Prepare the result based on the found sequence
    vector<int> result;
    result.push_back(start);
    if (maxLength > 1) {
        result.push_back(start + maxLength - 1);
    }

    return result;
}
