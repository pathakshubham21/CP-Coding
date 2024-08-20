// Problem statement
// Given a string S, find and return all the possible permutations of the input string.

// Note 1 : The order of permutations is not important. Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input :
// abc
// Sample Output :
// abc
// acb
// bac
// bca
// cab
// cba
#include <string>
#include <vector>
using namespace std;

// void returnPermutationsHelper(string input, int index, vector<string>& output) {
//     if (index == input.length()) {
//         output.push_back(input);
//         return;
//     }

//     for (int i = index; i < input.length(); i++) {
//         // Swap current index with the loop index
//         swap(input[index], input[i]);
//         // Recurse for the rest of the string
//         returnPermutationsHelper(input, index + 1, output);
//         // Swap back to restore the original string
//         swap(input[index], input[i]);
//     }
// }

// int returnPermutations(string input, string output[]) {
//     vector<string> permutations;
    
//     returnPermutationsHelper(input, 0, permutations);
    
//     for (int i = 0; i < permutations.size(); i++) {
//         output[i] = permutations[i];
//     }
    
//     return permutations.size();
// }

void returnPermutationsHelper(string input, string output, vector<string>& result) {
    if (input.length() == 0) {
        result.push_back(output);  // Base case: add the current permutation to the result
        return;
    }

    // Recursive case: build permutations by removing one character at a time
    for (int i = 0; i < input.length(); i++) {
        string newInput = input.substr(0, i) + input.substr(i + 1);  // New string after removing character at index i
        string newoutput = output + input[i];  // Append the removed character to the output
        returnPermutationsHelper(newInput, newoutput, result);  // Recursive call
    }
    return;
}

int returnPermutations(string input, string output[]) {
    vector<string> permutations;
    
    returnPermutationsHelper(input, "", permutations);  // Call the helper function
    
    for (int i = 0; i < permutations.size(); i++) {
        output[i] = permutations[i];  // Copy results to output array
    }
    
    return permutations.size();  // Return the number of permutations
}
