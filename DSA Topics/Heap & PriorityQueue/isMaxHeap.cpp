// Problem statement
// Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= N <= 10^5
// 1 <= Ai <= 10^5
// Time Limit: 1 sec
// Sample Input 1:
// 8
// 42 20 18 6 14 11 9 4
// Sample Output 1:
// true

bool isMaxHeap(int arr[], int n) {
    // Write your code here
    for(int i=0;i<n;i++)
    {
        int leftChildIndex = 2*i+1;
        int rightChildIndex = 2*i+2;
        if(leftChildIndex<n&& (arr[i]<arr[leftChildIndex]|| arr[i]<arr[rightChildIndex]))
        {
            return false;
        }
    }
    return true;
}