// Problem statement
// Given an input string (STR), print all possible permutations of the input string.

// Note:
// The input string may contain the same characters, so there will also be the same permutations.
// The order of permutations doesn’t matter.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// cba
// Sample Output 1:
// abc
// acb
// bac
// bca
// cab
// cba

#include <iostream>
#include <string>
using namespace std;

void permute(string &str, int l, int r) {
    if (l == r) {
        cout << str << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);        // Swap the current element with the first element
            permute(str, l + 1, r);      // Recurse for the rest of the string
            swap(str[l], str[i]);        // Backtrack by swapping the characters back
        }
    }
}

void printPermutations(string input) {
    int n = input.length();
    permute(input, 0, n - 1);
}
