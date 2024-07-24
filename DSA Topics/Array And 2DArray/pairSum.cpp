// Problem statement
// You have been given a sorted integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.

// Note:
// Given array/list can not contain duplicate elements. 
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= N <= 10^6
// 0 <= num <= 10^6
// Time Limit: 1 sec
// Sample Input 1:
// 5
// 1 2 3 4 5
// 7
// Sample Output 1:
// 2
// Sample Input 2:
// 5
// 1 2 3 4 5
// 10
// Sample Output 2:
// 0

int pairSum(int A[], int size, int K)
{
     // Write your code here.

     if(size==1 || A[0]+A[size-1]>K )
     return 0;


     int i=0;
     int j= size-1;
     int count= 0;

     while(i<j)
     {
          if(A[i]+A[j]==K)
          {
               count++;
               i++;
               j--;
          }
          else if(A[i]+A[j]<K)
          {
               i++;
          }
          else{
               j--;
          }
     }

     return count;
}