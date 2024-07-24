// Problem statement
// You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).

//  Note:
// Change in the input array/list itself.You don't need to return or print the elements.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= t <= 10^4
// 0 <= N <= 10^6
// 0 <= D <= N
// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 1 2 3 4 5 6 7
// 2
// Sample Output 1:
// 3 4 5 6 7 1 2
// Sample Input 2:
// 2
// 7
// 1 2 3 4 5 6 7
// 0
// 4
// 1 2 3 4
// 2
// Sample Output 2:
// 1 2 3 4 5 6 7
// 3 4 1 2

#include <algorithm>

// Function to reverse a segment of the array
void reverseArray(int *arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotate(int *input, int d, int n) {
    if (n == 0 || d == 0) return;  

    d = d % n;  // In case d is greater than n

    // Step 1: Reverse the first d elements
    reverseArray(input, 0, d - 1);

    // Step 2: Reverse the remaining elements
    reverseArray(input, d, n - 1);

    // Step 3: Reverse the entire array
    reverseArray(input, 0, n - 1);
}