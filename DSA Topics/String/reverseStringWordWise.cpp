// Problem statement
// Reverse the given string word-wise. The last word in the given string should come at 1st place, the last-second word at 2nd place, and so on. Individual words should remain as it is.
// Sample Input 1:
// Welcome to Coding Ninjas
// Sample Output 1:
// Ninjas Coding to Welcome
// Sample Input 2:
// Always indent your code
// Sample Output 2:
// code your indent Always


#include <iostream>
#include<string>
using namespace std;

string (string input) {
    string result = "";
    int length = input.length();
    int end = length;
    
    for (int i = length - 1; i >= 0; i--) {
        if (input[i] == ' ') {
            result += input.substr(i + 1, end - i - 1) + " ";
            end = i;
        }
    }
    
    result += input.substr(0, end);
    return result;
}

int main()
{
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    cout << ans << endl;
}