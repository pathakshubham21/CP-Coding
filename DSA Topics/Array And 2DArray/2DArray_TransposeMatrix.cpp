// Problem statement
// You are given a matrix ‘MAT’. Print the transpose of the matrix. The transpose of a matrix is obtained by changing rows to columns and columns to rows. In other words, transpose of a matrix A[][] is obtained by changing A[i][j] to A[j][i].

// For example:
// Let matrix be : 
// 1 2
// 3 4

// Then transpose of the matrix will be: 
// 1 3
// 2 4
// Note:
// You don't have to return anything just complete the function and print the final output.


void transpose(int row,int col,int input[][1001]) {

      int transposed[1001][1001];


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transposed[j][i] = input[i][j];
        }
    }


    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
    
    
}