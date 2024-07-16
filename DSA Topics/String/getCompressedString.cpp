// Problem statement
// Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.

// Example:
// If a string has 'x' repeated 5 times, replace this "xxxxx" with "x5".
// The string is compressed only when the repeated character count is more than 1.
// Note:
// Consecutive count of every character in the input string is less than or equal to 9. You are not required to print anything. It has already been taken care of. Just implement the given function and return the compressed string.


string getCompressedString(string &input) {
    // Write your code here.
    if(input.length()==1)
    return input;
    string result ="";
    int count = 0;
    int i=0,j=0;
    while(j<input.length())
    {
        if(input[i]==input[j])
        {
            count++;
            j++;
        }
        else {
        if(count>1){
            result+=input[i] + to_string(count);
        } 
        else {
            result += input[i];
        }
        i = j;
        count = 0;
        }
    }
// to take care of last charecter multiple occurance 
    if(count>1)
    {
        result+=input[i] + to_string(count);
    }
    else{
        result+=input[i];
    }

    return result;


}