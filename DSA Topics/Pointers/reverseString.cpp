// Problem statement
// You are given a string 'str' consisting of lower case alphabets. You have to find the reverse of the string.

// For example:
//  If the given string is: str = "abcde". You have to print the string "edcba".

void func(char *str) 
{
    //write your code here

    int left = 0;
    int right = 0;
    
    // Find the length of the string
    while (str[right] != '\0') {
        right++;
    }
    right--; // Set right to the last valid index

    // Swap characters from the ends towards the center
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}
