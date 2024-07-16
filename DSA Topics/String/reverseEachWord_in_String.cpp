// Problem statement
// Aadil has been provided with a sentence in the form of a string as a function parameter. The task is to implement a function so as to return the sentence such that each word in the sentence is reversed.

// Example:
// Input Sentence: "Hello, I am Aadil!"
// The expected output will print, ",olleH I ma !lidaA".


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string reverseEachWord(string str)
{
    string result ="";
    string temp="";
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==' ')
        {
            reverse(temp.begin(),temp.end());
            result+=temp+" ";
            temp="";
            continue;
        }
        temp+=str[i];
    }

    if(temp!="")
    {
        reverse(temp.begin(),temp.end());
        result+=temp;
    }
    return result;

}

int main()
{
    //Write your code here
    string str;
    getline(cin,str);
    cout<<reverseEachWord(str);
    return 0;

}