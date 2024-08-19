// Problem statement
// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.

// Note : The order of codes are not important. Just print them in different lines.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= Length of String S <= 10

// Sample Input:
// 1123
// Sample Output:
// aabc
// kbc
// alc
// aaw
// kw

#include <iostream>
#include <string>
using namespace std;

void generateCodes(string input, string currentOutput) {
    // Base case: If input is empty, print the current combination
    if (input.empty()) {
        cout << currentOutput << endl;
        return;
    }

    // Take the first digit and generate the corresponding character
    int firstDigit = input[0] - '0';
    if (firstDigit >= 1 && firstDigit <= 9) {
        char firstChar = 'a' + firstDigit - 1;
        generateCodes(input.substr(1), currentOutput + firstChar);
    }

    // Take the first two digits and generate the corresponding character, if valid
    if (input.length() >= 2) {
        int firstTwoDigits = stoi(input.substr(0, 2));
        if (firstTwoDigits >= 10 && firstTwoDigits <= 26) {
            char firstTwoChars = 'a' + firstTwoDigits - 1;
            generateCodes(input.substr(2), currentOutput + firstTwoChars);
        }
    }
}

void printAllPossibleCodes(string input) {
    generateCodes(input, "");
}
