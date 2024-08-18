// Problem statement
// Ninja is now bored with numbers and is now playing with characters but hates when he gets repeated characters. Ninja is provided a string, and he wants to return the first unique character in the string.The string will contain characters only from the English alphabet set, i.e., ('A' - 'Z') and ('a' - 'z'). If there is no non-repeating character, print the first character of the string. If there is no non-repeating character, return the first character of the string.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 10
// 1 <= Length of Input String <= 10^4

// Time Limit: 1 sec 
// Sample Input 1 :
// 2
// aDcadhc
// AabBcC
// Sample Output 1:
//  D
//  A
// Explanation for Sample Input 1:
// In the first test case, ‘a’ is repeated.’ D’ is the first non-repeating character in the string, so we return it.

// In the second test case, all the characters are non-repeating, so we return the first character.
// Sample Input 2 :
//  2
//  ABcd
//  AAAbcdb
// Sample Output 2:
//  A
//  c 

#include <unordered_map>
#include <string>
using namespace std;

char firstNonRepeatingCharacter(string str) {
    if (str.length() == 1) {
        return str[0];
    }

    unordered_map<char, int> mp;

    for (char c : str) {
        mp[c]++;
    }

    for (char c : str) {
        if (mp[c] == 1) {
            return c;
        }
    }

    return str[0];
}