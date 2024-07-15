// Problem statement
// You are given a 2D array of integers ‘A’ of length ’N’x’N’, where ‘N’ is the number of rows and column. You will be also be given an output array of length 'N' along the square matrix. Fill the array with diagonal elements of square matrix.

// A Square matrix is one that has an equal number of rows and columns.

// Note: You don't have to return anything. You just to fill the output array.

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6 
// 7 8 9

// Output: 
// 1 5 9

// Explanation:
// The number of rows and columns is equal, so the given array forms a square matrix.

void squareMatrix(int n,int arr[][100],int output[]){
    int k=0;
    //100 is just the upper limit, you just have to access till n
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                output[k++]=arr[i][j];
            }
        }
    }
    return;
    

}