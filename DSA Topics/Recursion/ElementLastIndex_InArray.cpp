// Problem statement
// Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.

// Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.

// You should start traversing your array from 0, not from (N - 1).

// Do this recursively. Indexing in the array starts from 0.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= N <= 10^3

// Sample Input :
// 4
// 9 8 10 8
// 8
// Sample Output :
// 3

int lastIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */

   if (size == 0) {
        return -1;
    }

    // Recursive call to check the rest of the array
    int index = lastIndex(input + 1, size - 1, x);

    // Check if the current element is equal to x
    if (input[0] == x) {
        // If x is found later in the array, return the updated index
        if(index==-1)
            return 0;

    } else {
        // If current element is not equal to x, return the index found in the recursive call
        if (index == -1) {
            return -1;
        } 
    }

    return index + 1;
}
