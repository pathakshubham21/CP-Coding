// Problem statement
// You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.

// Note: Take absolute difference between the elements of the array.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= n <= 10^4
// Time Limit: 1 sec
// Sample Input 1 :
// 4 
// 5 1 2 4
// 3
// Sample Output 1 : 
// 2
// Explanation
// (5,2) and (1,4) are the possible combinations as their absolute difference is 3.
// Sample Input 2 :
// 4
// 4 4 4 4 
// 0
// Sample Output 2 :
// 6

#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
	if(n==1)
	return -1;
	int count= 0;

	 unordered_map<int,int> mp;
	 for(int i=0;i<n;i++)
	 {
		 mp[arr[i]]++;
	 }
	 for(int i=0;i<n;i++)
	 {
		 int diff = arr[i] - k;
		 if(k==0 && mp[diff]!=0)
		 {
			 count += (mp[diff] * (mp[diff] - 1)) / 2;
			 mp[arr[i]] = 0;
		 }
		 else if(mp[diff]!=0)
		 {
			 count+=mp[diff];
		 }
	 }

	 return count;
}