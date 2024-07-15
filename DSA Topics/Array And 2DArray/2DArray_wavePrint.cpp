// Problem statement
// For a given two-dimensional integer array of size (N x M), print the array in a sine wave order, i.e, print the first column top to bottom, next column bottom to top and so on.




void wavePrint(int input[][1001], int nRows, int mCols)
{
   for (int col = 0; col < mCols; col++) {
        if (col % 2 == 0) {
            // Top to bottom
            for (int row = 0; row < nRows; row++) {
                cout << input[row][col] << " ";
            }
        } else {
            // Bottom to top
            for (int row = nRows - 1; row >= 0; row--) {
                cout << input[row][col] << " ";
            }
        }
    }
    cout << endl;
}