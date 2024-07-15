// Problem statement
// Aadil has been provided with a sentence in the form of a string as a function parameter. The task is to implement a function so as to change the sentence such that each word in the sentence is reversed. A word is a combination of characters without any spaces.

// Example:
// Input Sentence: "Hello I am Aadil"
// The expected output will look, "olleH I ma lidaA".

#include<cstring>
void reverseEachWord(char input[]) {

    int i=0,j=0;
    char temp;

    int n= strlen(input);
    for(int itr;itr<n;itr++)
    {
        if(input[itr]==' '|| itr==n-1)
        {
            j=(itr==(n-1)?itr:itr-1);
            while(i<j)
            {
                temp = input[i];
                input[i]=input[j];
                input[j] = temp;
                i++;
                j--;
            }
            i=itr+1;
        }
    }
    // Write your code here
}