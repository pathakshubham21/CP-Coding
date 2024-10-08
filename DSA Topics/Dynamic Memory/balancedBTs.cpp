// Problem statement
// Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.

// This number can be huge, so, return output modulus 10^9 + 7.

// Write a simple recursive solution.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= h <= 24
// Time Limit: 1 sec
// Sample Input 1:
// 3
// Sample Output 1:
// 15
// Sample Input 2:
// 4
// Sample Output 2:
// 315

#include <iostream>
using namespace std;
#include <cmath>


// h >= 0
int balancedBTs(int h) {
	if(h <= 1) {
		return 1;
	}

	int mod = (int) (pow(10, 9)) + 7;
	int x = balancedBTs(h - 1);
	int y = balancedBTs(h - 2);

	int temp1 = (int)(((long)(x)*x) % mod);
	int temp2 = (int)((2* (long)(x) * y) % mod);
	int ans = (temp1 + temp2) % mod;


	//int ans = (x*x + 2*x*y) % mod;
	return ans;
}
