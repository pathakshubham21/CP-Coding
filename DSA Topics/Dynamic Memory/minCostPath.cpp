// Problem statement
// An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).

// From a cell (i, j), you can move in three directions:

// 1. ((i + 1),  j) which is, "down"
// 2. (i, (j + 1)) which is, "to the right"
// 3. ((i+1), (j+1)) which is, "to the diagonal"
// The cost of a path is defined as the sum of each cell's values through which the route passes.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= M <= 10 ^ 2
// 1 <= N <=  10 ^ 2

// Time Limit: 1 sec
// Sample Input 1 :
// 3 4
// 3 4 1 2
// 2 1 8 9
// 4 7 8 1
// Sample Output 1 :
// 13
// Sample Input 2 :
// 3 4
// 10 6 9 0
// -23 8 9 90
// -200 0 89 200
// Sample Output 2 :
// 76
// Sample Input 3 :
// 5 6
// 9 6 0 12 90 1
// 2 7 8 5 78 6
// 1 6 0 5 10 -4 
// 9 6 2 -10 7 4
// 10 -2 0 5 5 7
// Sample Output 3 :
// 18


#include <iostream>
using namespace std;

int minCostPath(int **input, int m, int n, int i, int j) {
	// Base case
	if(i == m- 1 && j == n- 1) {
		return input[i][j];
	}

	if(i >= m || j >= n) {
		return INT_MAX;
	}

	// Recursive calls
	int x = minCostPath(input, m, n, i, j+1);
	int y = minCostPath(input, m, n, i+1, j+1);
	int z = minCostPath(input, m, n, i+1, j);

	// Small Calculation
	int ans = min(x, min(y, z)) + input[i][j];
	return ans;
}

int minCostPath(int **input, int m, int n) {
	return minCostPath(input, m, n, 0, 0);
}


/// Memoization solution int minCostPath_Mem(int **input, int m, int n, int i, int j, int **output) {
    if(i == m- 1 && j == n- 1) {
        return input[i][j];
    }
    
    if(i >= m || j >= n) {
        return INT_MAX;
    }
    
    // Check if ans already exists
    if(output[i][j] != -1) {
        return output[i][j];
    }
    
    // Recursive calls
    int x = minCostPath_Mem(input, m, n, i, j+1, output);
    int y = minCostPath_Mem(input, m, n, i+1, j+1, output);
    int z = minCostPath_Mem(input, m, n, i+1, j, output);
    
    // Small Calculation
    int a = min(x, min(y, z)) + input[i][j];
    
    // Save the answer for future use
    output[i][j] = a;
    
    return a;
}

int minCostPath_Mem(int **input, int m, int n, int i, int j) {
    int **output = new int*[m];
    for(int i = 0; i < m; i++) {
        output[i] = new int[n];
        for(int j = 0; j < n; j++) {
            output[i][j] = -1;
        }
    }
    
    return minCostPath_Mem(input, m, n, i, j, output);
}

int minCostPath(int **input, int m, int n, int i, int j) {
    // Base case
    if(i == m- 1 && j == n- 1) {
        return input[i][j];
    }
    
    if(i >= m || j >= n) {
        return INT_MAX;
    }
    
    // Recursive calls
    int x = minCostPath(input, m, n, i, j+1);
    int y = minCostPath(input, m, n, i+1, j+1);
    int z = minCostPath(input, m, n, i+1, j);
    
    // Small Calculation
    int ans = min(x, min(y, z)) + input[i][j];
    return ans;
}

int minCostPath(int **input, int m, int n) {
    return minCostPath(input, m, n, 0, 0);
}

