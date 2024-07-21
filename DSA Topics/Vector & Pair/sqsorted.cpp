// Problem statement
// You are given an array/list ‘ARR’ of ‘N’ integers. You have to generate an array/list containing squares of each number in ‘ARR’, sorted in increasing order.

// For example :

// Input:
// ‘ARR’ = [-6,-3, 2, 1, 5] 

// If we take a square of each element then the array/list will become [36, 9, 4, 1, 25].
// Then the sorted array/list will be [1, 4, 9, 25, 36].

// Output :
// [1, 4, 9, 25, 36].
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 4 
// -3 -3 1 2
// 6 
// 0 1 2 3 4 5 
// Sample Output 1:
// 1 4 9 9 
// 0 1 4 9 16 25

#include <bits/stdc++.h> 
vector < int > sqsorted(vector < int > & arr) {

    vector<int>sqsorted_array(arr.size());

    for(int i=0;i<arr.size();i++)
    {
        sqsorted_array[i]=arr[i]*arr[i];
    }
    sort(sqsorted_array.begin(),sqsorted_array.end());
    return sqsorted_array;
    // Write your code here.
}