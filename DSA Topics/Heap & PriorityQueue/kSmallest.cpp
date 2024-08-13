// Problem statement
// You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.

// Time complexity should be O(n * logk) and space complexity should not be more than O(k).

// Note: Order of elements in the output is not important.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// Time Limit: 1 sec
// Sample Input 1 :
// 13
// 2 12 9 16 10 5 3 20 25 11 1 8 6 
// 4
// Sample Output 1 :
// 1 2 3 5 

#include<vector>
#include<queue>
vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    if(k>n)
    {
        return {};
    }
    priority_queue<int>pq;
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    vector<int>result;
    for(int i=k;i<n;i++)
    {
        if(arr[i]<pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(!pq.empty())
    {
        result.push_back(pq.top());
        pq.pop();
    }

    // reverse(result.begin(),result.end());

    return result;

}