// Problem statement
// You are given a string ‘S’ of length ‘N’ representing an integer.



// Beauty of a string is the difference between the frequency of the most frequently occurring character and the least frequently occurring character.



// You must return the sum of beauty of all substrings of string ‘S’.



// Note:
// A substring is a string formed after deleting zero or more characters from both ends of a string.


// Example:
// Input:
// S = “hello"

// Output:
// 5

// Explanation: The following substring ‘hell’, ‘ell’, ‘llo’, ‘ello’, and ‘hello’ has the beauty of 1. Hence we return 5.


#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
int calculateBeauty(unordered_map<char, int>& freqMap) {
    int minFreq = INT_MAX;
    int maxFreq = INT_MIN;
    for (auto& entry : freqMap) {
        if (entry.second > 0) {
            minFreq = min(minFreq, entry.second);
            maxFreq = max(maxFreq, entry.second);
        }
    }
    return maxFreq - minFreq;
}

int sumOfBeauty(string s) {
    int n = s.length();
    int result = 0;

    for (int i = 0; i < n; ++i) {
        unordered_map<char, int> freqMap;
        for (int j = i; j < n; ++j) {
            freqMap[s[j]]++;
            result += calculateBeauty(freqMap);
        }
    }

    return result;
}
