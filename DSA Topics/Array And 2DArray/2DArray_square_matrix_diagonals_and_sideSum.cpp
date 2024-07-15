// Problem statement
// For a given two-dimensional square matrix of size (N x N). Find the total sum of elements on both the diagonals and at all the four boundaries.

// Sample input 1:
// 3
// 1 2 3
// 4 5 6
// 7 8 9
// Sample Output 1:
// 45
// Explanation for Sample Output 1:
// The boundary elements are 1, 2, 3, 6, 9, 8, 7 and 4. 

// The first-diagonal elements are 1, 5 and 9. 

// The second-diagonal elements are 3, 5 and 7.

// We just need to add all these numbers making sure that no number is added twice. For example, '1' is both a boundary element and a first-diagonal element similarly, '5' contributes to both the diagonals but they won't be added twice.

// Hence, we add up, [1 + 2 + 3 + 6 + 9 + 8 + 7 + 4 + 5] to give 45 as the output.


int totalSum(int input[][501], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // Checking for primary diagonal (i == j)
            // Checking for secondary diagonal (i + j == n - 1)
            // Checking for boundaries (i == 0, i == n-1, j == 0, j == n-1)
            if (i == j || i + j == n - 1 || i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                sum += input[i][j];
            }
        }
    }
    return sum;
}
