// Problem statement
// For a given a string(str), find and return the highest occurring character.

// Example:
// Input String: "abcdeapapqarr"
// Expected Output: 'a'
// Since 'a' has appeared four times in the string which happens to be the highest frequency character, the answer would be 'a'.
// If there are two characters in the input string with the same frequency, return the character which comes first.

// Consider:
// Assume all the characters in the given string to be in lowercase always.


#include<cstring>
char highestOccurringChar(char input[]) {
    // Write your code here

    static int hasmap[200];
    int max = 0;
    char answer;
    int n = strlen(input);

    for(int i=0;i<n;i++)
    {
        hasmap[input[i]]++;
    }

    for(int i=0;i<n;i++)
    {
        if(hasmap[input[i]]>max)
        {
            answer = input[i];
            max = hasmap[input[i]];
        }
    }
    return answer;
}