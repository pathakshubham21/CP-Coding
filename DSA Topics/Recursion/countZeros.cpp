// Problem statement
// Given an integer N, count and return the number of zeros that are present in the given integer using recursion.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= N <= 10^9
// Sample Input 1 :
// 0
// Sample Output 1 :
// 1
// Sample Input 2 :
// 00010204
// Sample Output 2 :
// 2

int countZeros(int n) {
      if (n == 0) {
        return 1;
    }
    // Base case: if n is reduced to 0, no more zeros to count
    if (n < 10) {
        return 0;
    }

    // Check the last digit of n
    int lastDigit = n % 10;

    // Recursively count zeros in the rest of the number
    int count = countZeros(n / 10);

    // If the last digit is zero, increment the count
    if (lastDigit == 0) {
        count++;
    }

    return count;

    // Write your code here

}


