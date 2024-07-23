// Problem statement
// Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 < |S| <= 9
// where |S| represents length of string S.
// Sample Input 1 :
// 00001231
// Sample Output 1 :
// 1231
// Sample Input 2 :
// 12567
// Sample Output 2 :
// 12567

#include<algorithm>
#include<cstring>
int stringToNumber(char input[]) {
    // Write your code here
      if (input[0] == '\0') {
        return 0;
    }

    // Recursive call to process the rest of the string
    int smallerNumber = stringToNumber(input + 1);

    // Calculate the current digit by subtracting '0' from the current character
    int currentDigit = input[0] - '0';

    // Calculate the place value for the current digit
    int placeValue = currentDigit * pow(10, strlen(input) - 1);

    // Return the combined result
    return placeValue + smallerNumber;

}


