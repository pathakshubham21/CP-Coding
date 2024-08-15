// Problem statement
// Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.



// Note:
// Array A can contain duplicate elements as well.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= N <= 10^4
// Time Limit: 1 sec
// Sample Input 1:
// 5
// 2 1 -2 2 3
// Sample Output 1:
// 2
// Explanation
// (2,-2) , (-2,2) will result in 0 , so the answer for the above problem is 2.

#include <unordered_map>
int pairSum(int *arr, int n) {
	// Write your code here

	if(n==1)
	return -1;
	int result = 0;
	unordered_map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		int complement = -arr[i];
		if(mp[complement]>0)
		{
			result+=mp[complement];
		}
		mp[arr[i]]++;

		
	
	}

	return result;



}