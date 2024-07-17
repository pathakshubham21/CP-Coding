// Problem statement
// Given a string ‘str’ and a pattern ‘pat’, you have to find all occurrences of the pattern in the string. You have to print the starting positions of all occurrences of the pattern in the string.
// Sample Input 1:
// ‘str’ = “heyhihey”
// ‘pat’ = “hey”
// Sample Output 1:
// 0 5


#include<iostream>
#include<string>
using namespace std;

void Occurrences_of_Pattern(string str, string pat)
{
    int i=0,j=0;
    int strN= str.length();
    int patN = pat.length(); 

    if(patN>strN)
        return;

    for(int itr=0;itr<strN-patN+1; itr++)
    {
        if(str[itr]==pat[j])
        {
            i=itr;
            j=0;

            while(j<patN)
            {
                if(str[i++]!=pat[j++])
                {
                    break;
                }
            }
             if(j==patN)
                cout<<itr<<" ";
            j=0;
        }

    }
}

int main(){

    string str,pat;
    cin>>str>>pat;
    Occurrences_of_Pattern(str,pat);
}