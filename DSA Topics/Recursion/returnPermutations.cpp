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

void returnPermutationsHelper(string input, int index, vector<string>& output) {
    if (index == input.length()) {
        output.push_back(input);
        return;
    }

    for (int i = index; i < input.length(); i++) {
        // Swap current index with the loop index
        swap(input[index], input[i]);
        // Recurse for the rest of the string
        returnPermutationsHelper(input, index + 1, output);
        // Swap back to restore the original string
        swap(input[index], input[i]);
    }
}

int returnPermutations(string input, string output[]) {
    vector<string> permutations;
    
    returnPermutationsHelper(input, 0, permutations);
    
    for (int i = 0; i < permutations.size(); i++) {
        output[i] = permutations[i];
    }
    
    return permutations.size();
}
