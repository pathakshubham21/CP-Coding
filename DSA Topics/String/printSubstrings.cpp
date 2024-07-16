// Problem statement
// For a given input string(str), write a function to print all the possible substrings.

// Substring
// A substring is a contiguous sequence of characters within a string. 
// Example: "cod" is a substring of "coding". Whereas "cdng" is not as the characters taken are not contiguous


#include <bits/stdc++.h> 
#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(string input) {
    //Write your code here
    string substring="";
    for(int i=0;i<input.length();i++)
    {
        for(int j=i;j<input.length();j++)
        {
            substring+=input[j];
            cout<<substring<<endl;
        }
        substring = "";
    }
}

int main() {
    string input;
    getline(cin, input);
    printSubstrings(input);
    return 0;
}