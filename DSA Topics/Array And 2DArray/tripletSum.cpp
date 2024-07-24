// Problem statement
// You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.

// Note :
// Given array/list can contain duplicate elements.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^3
// 0 <= X <= 10^9

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 1 2 3 4 5 6 7 
// 12
// Sample Output 1:
// 5
// Sample Input 2:
// 2
// 7
// 1 2 3 4 5 6 7 
// 19
// 9
// 2 -5 8 -6 0 5 10 11 -3
// 10
// Sample Output 2:
// 0
// 5


//  Explanation for Input 2:
// Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.

// For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)

#include <algorithm>

int tripletSum(int *arr, int n, int num) {
    std::sort(arr, arr + n);
    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum == num) {
                // Count occurrences of arr[left]
                int leftValue = arr[left];
                int rightValue = arr[right];
                int leftCount = 0;
                int rightCount = 0;

                while (left < right && arr[left] == leftValue) {
                    leftCount++;
                    left++;
                }

                while (left <= right && arr[right] == rightValue) {
                    rightCount++;
                    right--;
                }

                // If leftValue and rightValue are the same, we need to handle it differently
                if (leftValue == rightValue) {
                    count += (leftCount * (leftCount - 1)) / 2;
                } else {
                    count += leftCount * rightCount;
                }
            } else if (sum < num) {
                left++;
            } else {
                right--;
            }
        }

        // Skip duplicates for the first element of the triplet
        while (i + 1 < n && arr[i] == arr[i + 1]) {
            i++;
        }
    }

    return count;
}
