// Problem statement
// Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 0 <= N <= 10^8
// Time Limit: 1 sec
// Sample Input 1:
// 10 
//  95 -97 -387 -435 -5 -70 897 127 23 284
// Sample Output 1:
// 5
// Explanation:
// The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 
// Note
// You don't have to print anything. Just complete the definition of the function given and return the value accordingly.

#include <vector>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == 0) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}


// #include <unordered_map>
// #include <vector>
// using namespace std;

// int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
//     unordered_map<int, int> cumSumMap;
//     int cumSum = 0;
//     int maxLength = 0;

//     for (int i = 0; i < n; i++) {
//         cumSum += arr[i];

//         if (cumSum == 0) {
//             maxLength = i + 1;
//         }

//         if (cumSumMap.find(cumSum) != cumSumMap.end()) {
//             maxLength = max(maxLength, i - cumSumMap[cumSum]);
//         } else {
//             cumSumMap[cumSum] = i;
//         }
//     }

//     return maxLength;
// }
