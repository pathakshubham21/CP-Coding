// Problem statement
// You are given a N*N maze with a rat placed at maze[0][0]. Find whether any path exist that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).

// Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 0 < N < 11 0 <= Maze[i][j] <=1

// Time Limit: 1sec
// Sample Input 1 :
// 3
// 1 0 1
// 1 0 1
// 1 1 1
// Sample Output 1 :
// true
// Sample Input 2 :
// 3
// 1 0 1
// 1 0 1
// 0 1 1
// Sample Output 2 :
False 

bool isSafe(int maze[20][20], int x, int y, int n, bool visited[20][20]) {
    // Check if (x, y) is within maze bounds, the cell is not blocked, and it hasn't been visited yet
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]);
}

bool solveMazeUtil(int maze[20][20], int x, int y, int n, bool visited[20][20]) {
    // If the rat reaches the destination (bottom-right corner)
    if (x == n-1 && y == n-1) {
        return true;
    }

    // Mark the current cell as visited
    visited[x][y] = true;

    // Move right (in the x direction)
    if (isSafe(maze, x + 1, y, n, visited)) {
        if (solveMazeUtil(maze, x + 1, y, n, visited)) {
            return true;
        }
    }

    // Move down (in the y direction)
    if (isSafe(maze, x, y + 1, n, visited)) {
        if (solveMazeUtil(maze, x, y + 1, n, visited)) {
            return true;
        }
    }

    // Move left (in the x direction)
    if (isSafe(maze, x - 1, y, n, visited)) {
        if (solveMazeUtil(maze, x - 1, y, n, visited)) {
            return true;
        }
    }

    // Move up (in the y direction)
    if (isSafe(maze, x, y - 1, n, visited)) {
        if (solveMazeUtil(maze, x, y - 1, n, visited)) {
            return true;
        }
    }

    // Backtrack: unmark x, y as part of the solution path
    visited[x][y] = false;
    return false;

}

bool ratInAMaze(int maze[20][20], int n) {
    // Create a visited array to keep track of the visited cells
    bool visited[20][20] = {false};

    // Call the utility function to solve the maze problem
    return solveMazeUtil(maze, 0, 0, n, visited);
}
