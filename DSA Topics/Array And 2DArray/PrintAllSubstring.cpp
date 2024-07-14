// Problem statement
// For a given input string(str), write a function to print all the possible substrings.

// Substring
// A substring is a contiguous sequence of characters within a string. 
// Example: "cod" is a substring of "coding". Whereas, "cdng" is not as the characters taken are not contiguous


#include<cstring>
void printSubstrings(char input[]) {
    // Write your code here
    int n= strlen(input);
   for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            for (int k = i; k <= j; ++k) {
             cout << input[k];
            }
    cout << std::endl;
        }
    }
}