// Problem statement
// Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= Length of S <= 10^8
// Time Limit: 1 sec
// Sample Input 1 :
// ababacd
// Sample Output 1 :
// abcd
// Sample Input 2 :
// abcde
// Sample Output 2 :
// abcde

#include<unordered_map>

string uniqueChar(string str) {
	// Write your code here
	if(str.length()==1)
	return str;

	string result ="";
	unordered_map<int,int>mp;
	for(int i=0;i<str.length();i++)
	{
		if(mp[str[i]]==0)
		{
			result+=str[i];
			mp[str[i]]++;
		}
	}
	return result;

}