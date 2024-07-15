// Problem statement
// For a given two strings, 'str1' and 'str2', check whether they are a permutation of each other or not.

// Permutations of each other
// Two strings are said to be a permutation of each other when either of the string's characters can be rearranged so that it becomes identical to the other one.

// Example: 
// str1= "sinrtg" 
// str2 = "string"

// The character of the first string(str1) can be rearranged to form str2 and hence we can say that the given strings are a permutation of each other.

// Sample Input 1:
// abcde
// baedc
// Sample Output 1:
// true
// Sample Input 2:
// abc
// cbd
// Sample Output 2:
// false

#include<cstring>

bool isPermutation(char input1[], char input2[]) {
    // Write your code here

    int len1 = strlen(input1);
    int len2 = strlen(input2);
    if(len1!=len2)
    return false;

   static int hasmap[200];

    for(int i=0;i<len1;i++)
    {
        hasmap[input1[i]]++;
    }


     for(int i=0;i<len2;i++)
    {
        if (hasmap[input2[i]] > 0) 
        {
          hasmap[input2[i]]--;
        }
         else {
          return false;
        }
    }
    
    return true;



}