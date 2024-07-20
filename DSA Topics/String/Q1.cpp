// ; Problem statement
// ; Write as you speak is a special sequence of strings that starts with string “1” and after one iteration you rewrite the sequence as whatever you speak.

// ; Example :
// ; The first few iterations of the sequence are :
// ; First iteration: “1”
// ;     As we are starting with one.

// ; Second iteration: “11”
// ;     We speak “1” as   “one 1” then we write it as “11”

// ; Third iteration: “21”
// ;     We speak “11” as “Two 1” then we write it as “21”

// ; Fourth iteration: “1211”
// ;     We speak “21” as “one 2, one 1”  then we write it as “1211”

// ; Fifth iteration: “111221”
// ;     We speak “1211” as “one 1, one 2, two 1” then we write it as “111221”

// ; Sixth iteration: “312211”
// ;     We speak “111221” as “three 1, two 2, one 1” then we write it as “312211”
// ; You will be given a single positive integer N, Your task is to write the sequence after N iterations.

// Sample Input 1 :
// 2
// 1
// 2
// Sample Output 1:
// 1
// 11
// Explanation For Sample Input 2:
// First iteration: “1”
//     As we are starting with one.

// Second iteration: “11”
//     We speak “1” as   “one 1” then we write it as “11”
// Sample Input 2 :
// 2
// 3
// 4
// Sample Output 2:
// 21
// 1211

#include <iostream>
#include <string>

std::string generateSequence(int n) {
    if (n <= 0) return "";
    
    std::string result = "1";  // Initial string
    
    for (int i = 1; i < n; ++i) {
        std::string newResult;
        int count = 1;
        char currentChar = result[0];
        
        for (size_t j = 1; j < result.length(); ++j) {
            if (result[j] == currentChar) {
                ++count;
            } else {
                newResult += std::to_string(count);
                newResult += currentChar;
                currentChar = result[j];
                count = 1;
            }
        }
        
        // Append the last counted character
        newResult += std::to_string(count);
        newResult += currentChar;
        
        result = newResult;
    }
    
    return result;
}

int main() {
    int n = 6;  // Example: number of iterations
    std::cout << "The sequence after " << n << " iterations is: " << generateSequence(n) << std::endl;
    return 0;
}
