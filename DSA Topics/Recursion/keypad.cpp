// Problem statement
// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.

// Return empty string for numbers 0 and 1.

// Note :
// 1. The order of strings are not important.
// 2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= n <= 10^6

// Sample Input:
// 23
// Sample Output:
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf

#include <string>
#include <vector>
using namespace std;

// Helper function to generate all possible combinations
void generate_combinations(int num, string current_combination, vector<string>& output, const vector<string>& keypad_mapping) {
    if (num == 0) {
        output.push_back(current_combination);
        return;
    }
    
    int last_digit = num % 10;
    num /= 10;
    
    if (last_digit == 0 || last_digit == 1) {
        return;
    }
    
    for (char ch : keypad_mapping[last_digit]) {
        generate_combinations(num, ch + current_combination, output, keypad_mapping);
    }
}

int keypad(int num, string output[]) {
    if (num == 0 || num == 1) {
        return 0;
    }
    
    vector<string> keypad_mapping = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    vector<string> result;
    generate_combinations(num, "", result, keypad_mapping);
    
    for (int i = 0; i < result.size(); i++) {
        output[i] = result[i];
    }
    
    return result.size();
}