// Problem statement
// You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.

// Time complexity should be O(nlogk) and space complexity should be not more than O(k).

// Order of elements in the output is not important.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input :
// 13
// 2 12 9 16 10 5 3 20 25 11 1 8 6 
// 4
// Sample Output :
// 12
// 16
// 20
// 25

#include<vector>
#include<queue>
vector<int> kLargest(int input[], int n, int k){
     if(k>n)
     return {};

     priority_queue<int, vector<int>, greater<int>>pq;
     vector<int>result;

     for(int i=0;i<k;i++)
     {
         pq.push(input[i]);
     }

     for(int i=k;i<n;i++)
     {
         if(input[i]>pq.top())
         {
             pq.pop();
             pq.push(input[i]);
         }
        
     }
     while(!pq.empty())
     {
         result.push_back(pq.top());
         pq.pop();
     }

     return result;

}
