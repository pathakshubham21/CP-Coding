// Problem statement
// Write a program to take a matrix of size m*n as the input from the user and print the transpose of the matrix. The transpose of a matrix is obtained by changing rows to columns and columns to rows. In other words, transpose of a matrix A[][] is obtained by changing A[i][j] to A[j][i]. Use dynamic memory allocation to create the 2D arrays.

// For example:
// Let matrix be : 
// 1 2
// 3 4

// Then transpose of the matrix will be: 
// 1 3
// 2 4



#include <iostream>
using namespace std;

int main() {
    int m, n;

    // Read number of matrices
    int number_of_matrices;
    cin >> number_of_matrices;

    while (number_of_matrices--) {
        // Get the size of the matrix from the input
        cin >> m >> n;

        // Dynamically allocate memory for the matrix
        int** matrix = new int*[m];
        for(int i = 0; i < m; ++i) {
            matrix[i] = new int[n];
        }

        // Get the matrix elements from the input
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }

        // Dynamically allocate memory for the transpose matrix
        int** transpose = new int*[n];
        for(int i = 0; i < n; ++i) {
            transpose[i] = new int[m];
        }

        // Compute the transpose of the matrix
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                transpose[j][i] = matrix[i][j];
            }
        }

        // Print the transpose matrix
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cout << transpose[i][j] << " ";
            }
            cout << endl;
        }

        // Free the allocated memory
        for(int i = 0; i < m; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;

        for(int i = 0; i < n; ++i) {
            delete[] transpose[i];
        }
        delete[] transpose;

        // Print a blank line to separate matrices' transposes
        if (number_of_matrices > 0) {
            cout << endl;
        }
    }

    return 0;
}
