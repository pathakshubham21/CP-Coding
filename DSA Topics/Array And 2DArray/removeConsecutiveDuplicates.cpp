// Problem statement
// For a given string(str), remove all the consecutive duplicate characters.

// Example:
// Input String: "aaaa"
// Expected Output: "a"

// Input String: "aabbbcc"
// Expected Output: "abc"
//  Input Format:
// The first and only line of input contains a string without any leading and trailing spaces. All the characters in the string would be in lower case.

#include<cstring>
void removeConsecutiveDuplicates(char input[]) {
    // Write your code here
    int n = strlen(input);
    int k=0;

    for(int i=0;i<n-1;i++)
    {
        if(input[i]!=input[i+1])
        {
            input[k++]=input[i];
        }
    }
    input[k]= input[n-1];
    input[k+1] = '\0';

}