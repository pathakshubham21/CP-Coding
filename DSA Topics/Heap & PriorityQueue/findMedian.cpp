#include<vector>
#include<algorithm>

// Problem statement
// You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.

// Print only the integer part of the median.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 6
// 6 2 1 3 7 5
// Sample Output 1 :
// 6 4 2 2 3 4
// Explanation of Sample Output 1 :
// S = {6}, median = 6
// S = {6, 2} -> {2, 6}, median = 4
// S = {6, 2, 1} -> {1, 2, 6}, median = 2
// S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
// S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
// S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
// Sample Input 2 :
// 5
// 5 4 3 2 1
// Sample Output 2 :
// 5 4 4 3 3
// void findMedian(int *arr, int n)
// {
//     // Write your code here
//     if(n==0)
//     return;
//     if (n == 1) {
//       cout <<arr[0];
//       return;
//     }
//     vector<int>res;
//     res.push_back(arr[0]);
//     cout<<res[0];
//     int size;
//     for(int i=1;i<n;i++)
//     {
//         res.push_back(arr[i]);
//         size = res.size();
//         cout<<" ";
//         if(size%2==1)
//         {
//             sort(res.begin(),res.end());
//             cout<<res[size/2];
//         }
//         else{
//             sort(res.begin(),res.end());
//             int Medianvalue = (res[size/2-1]+res[size/2])/2;
//             cout<<Medianvalue;
//         }
        
//     }
//     return;
// }
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void findMedian(int *arr, int n) {
    if (n == 0) return;

    priority_queue<int> maxHeap; // Max heap for the lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for the upper half

    for (int i = 0; i < n; ++i) {
        int num = arr[i];

        // Insert into the max heap first
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Output the current median
        if (maxHeap.size() == minHeap.size()) {
            cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
        } else {
            cout << maxHeap.top() << " ";
        }
    }
}
