// Problem statement
// You are given an array ‘Arr’ consisting of ‘N’ distinct integers and a positive integer ‘K’. Find out Kth smallest and Kth largest element of the array. It is guaranteed that K is not greater than the size of the array.

// Example:

// Let ‘N’ = 4,  ‘Arr’ be [1, 2, 5, 4] and ‘K’ = 3.  
// then the elements of this array in ascending order is [1, 2, 4, 5].  Clearly, the 3rd smallest and largest element of this array is 4 and 2 respectively.

// Sample Input 1:
// 4 4
// 5 6 7 2
// 4 3
// 1 2 5 4
// Sample Output 1:
// 7 2 
// 4 2
// Explanation of Sample Input 1:
// Test case 1:
// Here, ‘N’ = 4, ‘Arr’ = [5, 6, 7, 2] and ‘K’ = 3.
// Elements of the array in ascending order are [2, 5, 6, 7]
// Thus the 4rd smallest and 4rd largest elements of this array are 7 and 2 respectively.


#include <vector>
#include <algorithm>  
using namespace std;

vector<int> kthSmallLarge(vector<int> &arr, int n, int k) {

    sort(arr.begin(), arr.end());

    int kthSmallest = arr[k - 1];
    int kthLargest = arr[n - k];

    vector<int> result;
    result.push_back(kthSmallest);
    result.push_back(kthLargest);

    return result;
}
