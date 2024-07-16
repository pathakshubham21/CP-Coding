// Problem statement
// Given a string and a character X, write a function to remove all occurrences of the character X from the string.

void removeAllOccurrencesOfChar(string input, char c) 
{
    int n = input.length();
    int j = 0;  // Pointer to place the next character that is not 'c'

    for (int i = 0; i < n; i++) {
        if (input[i] != c) {
            input[j] = input[i];
            j++;
        }
    }

    // Resize the string to remove the trailing characters
    input.resize(j);
    cout<<input;
}