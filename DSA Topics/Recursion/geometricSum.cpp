// Problem statement
// Given k, find the geometric sum i.e.

// 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
// Note :
// using recursion.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= k <= 1000
// Sample Input 1 :
// 3
// Sample Output 1 :
// 1.87500
// Sample Input 2 :
// 4
// Sample Output 2 :
// 1.93750
// Explanation for Sample Input 1:
// 1+ 1/(2^1) + 1/(2^2) + 1/(2^3) = 1.87500

double geometricSum(int k) {
    // Write your code here
    // Base case: if k is 0, the sum is 1 (since 1/(2^0) = 1)
    if (k == 0) {
        return 1.0;
    }

    // Recursive case: 1/(2^k) + geometricSum(k-1)
    double smallSum = geometricSum(k - 1);
    double currentTerm = 1.0 / (1 << k); // 1/(2^k)
    return currentTerm + smallSum;
}

