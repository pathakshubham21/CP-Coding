// Problem statement
// Write a function that takes a string as input and determines if it is a palindrome or not, considering only alphanumeric characters.

// Note:
// You are not required to print anything. It has already been taken care of. 


bool checkPalindrome(string str) {

    int i=0;
    int j = str.length()-1;

    if(str.length()==1)
    return true;


    while(i<j)
    {
        if(str[i]!=str[j])
        return false;

        i++;
        j--;
    }

    return true;
    
}