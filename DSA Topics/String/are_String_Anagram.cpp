// Problem statement
// You have been given two strings 'STR1' and 'STR2'. You have to check whether the two strings are anagram to each other or not.

// Note:
// Two strings are said to be anagram if they contain the same characters, irrespective of the order of the characters.
// Example :
// If 'STR1' = “listen” and 'STR2' = “silent” then the output will be 1.

// Both the strings contain the same set of characters.

#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    if(str1==str2)
    return true;
    else
    return false;
}