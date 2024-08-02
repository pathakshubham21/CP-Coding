// Problem statement
// For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.

// If the expression can't be balanced, return -1.

// Example:
// Expression: {{{{
// If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

// Expression: {{{
// In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 0 <= N <= 10^6
// Where N is the length of the expression.

// Time Limit: 1sec
// Sample Input 1:
// {{{
// Sample Output 1:
// -1
// Sample Input 2:
// {{{{}}
// Sample Output 2:



#include<stack>
int countBracketReversals(string input) {
	// Write your code here
	if(input.length()%2==1)
	return -1;

	stack<char>st;

	for(int i=0;i<input.length();i++)
	{
		if(input[i]=='{')
		{
			st.push(input[i]);
		}
		else{
					if (!st.empty() && st.top() == '{') {
						st.pop();
					} 
					else {
						st.push(input[i]);
					}
                }
	}

	if(st.empty())
	return 0;

	// cout<<st.size();


	int countOpen = 0;
	int countClose = 0;

	while(!st.empty())
	{
		if(st.top()=='{')
		countOpen++;
		else
		countClose++;
		st.pop();
	}


		int ans  = 0;
		if(countOpen%2==0)
		{
			ans +=countOpen/2;

		}
		else {
			ans += countOpen/2+1;
		}
		if(countClose%2==0)
		{
			ans +=countClose/2;

		}
		else {
			ans += countClose/2+1;
		}

		return ans;
		
	




}