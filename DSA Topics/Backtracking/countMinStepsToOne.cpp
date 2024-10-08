// Problem statement
// Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:

// 1.) Subtract 1 from it. (n = n - ­1) ,
// 2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
// 3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
// Write brute-force recursive solution for this.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= n <= 200

// Time Limit: 1 sec
// Sample Input 1 :
// 4
// Sample Output 1 :
// 2 
// Explanation of Sample Output 1 :
// For n = 4
// Step 1 :  n = 4 / 2  = 2
// Step 2 : n = 2 / 2  =  1 
// Sample Input 2 :
// 7
// Sample Output 2 :
// 3
// Explanation of Sample Output 2 :
// For n = 7
// Step 1 :  n = 7 ­- 1 = 6
// Step 2 : n = 6  / 3 = 2 
// Step 3 : n = 2 / 2 = 1  

#include<limits>

int countMinStepsToOne(int n)
{
	//Write your code here
	if(n<=1)
	return 0;

	int x,y,z;
	y= INT_MAX;
	z= INT_MAX;

	x= countMinStepsToOne(n-1);

	if(n%2==0)
	y= countMinStepsToOne(n/2);

	if(n%3==0)
	z= countMinStepsToOne(n/3);

	int ans = min(x,min(y,z))+1;

	return ans;
}

// DP solution 

#include <bits/stdc++.h>
using namespace std;

int static arr[1000001]; // Updated the size to 10^6 + 1

int countStepsToOne(int n) {
    // Base case: if n is 1, no more steps are needed
    if (n <= 1)
        return 0;

    // If we have already computed the answer for this 'n', return it
    if (arr[n] != 0)
        return arr[n];

    // Recursive calls for the three possible operations
    int x = countStepsToOne(n - 1);
    int y = INT_MAX;
    int z = INT_MAX;

    if (n % 2 == 0) {
        y = countStepsToOne(n / 2);
    }

    if (n % 3 == 0) {
        z = countStepsToOne(n / 3);
    }

    // Find the minimum steps required and store it in the array
    arr[n] = min(x, min(y, z)) + 1;

    return arr[n];
}