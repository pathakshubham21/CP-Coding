#include <cstring> 

bool checkPalindrome(char arr[]) {
    // Write your code here
    int n = strlen(arr);

    int i=0,j=n-1;

    while(i<j)
    {
        if(arr[i]!=arr[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
