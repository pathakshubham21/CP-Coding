// Problem statement
// Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in the output array (in increasing order).

// Do this recursively. Indexing in the array starts from 0.

// Hint:
// Try making a helper function with the required arguments and call the helper function from the allIndexes function.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= N <= 10^3
// Sample Input :
// 5
// 9 8 10 8 8
// 8
// Sample Output :
// 1 3 4


void allIndexesHelper(int input[], int size, int x, int output[], int currentIndex, int &outputIndex) {
    // Base case: If the size is 0, return
    if (currentIndex == size) {
        return;
    }

    // If the current element matches x, store the index in the output array
    if (input[currentIndex] == x) {
        output[outputIndex] = currentIndex;
        outputIndex++;
    }

    // Recursively call for the next element in the array
    allIndexesHelper(input, size, x, output, currentIndex + 1, outputIndex);
}

int allIndexes(int input[], int size, int x, int output[]) {
    int outputIndex = 0;
    allIndexesHelper(input, size, x, output, 0, outputIndex);
    return outputIndex;
}