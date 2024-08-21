 string direction = "DLRU";  // Directions for the movements
    
    // Arrays to represent change in rows and columns
    int dr[4] = { 1, 0, 0, -1 };
    int dc[4] = { 0, -1, 1, 0 };

    // Function to check if a move is valid
    bool isSafe(int row, int col, vector<vector<int>>& mat, int n) {
        return (row >= 0 && row < n && col >= 0 && col < n && mat[row][col] == 1);
    }

    // Recursive backtracking function
     void solve(vector<vector<int>>& mat, int n, int row, int col, string &path, vector<string>& result) {
        // Base case: If the destination (n-1, n-1) is reached
        if (row == n - 1 && col == n - 1) {
            result.push_back(path);
            return;
        }

        // Try all possible directions: D, L, R, U
        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            if (isSafe(newRow, newCol, mat, n)) {   
                // Mark the cell as visited
                mat[newRow][newCol] = 0;

                // Add the current direction to the path
                path.push_back(direction[i]);

                // Recur for the next cell
                solve(mat, n, newRow, newCol, path, result);

                // Backtrack: Unmark the visited cell and remove the direction from the path
                mat[newRow][newCol] = 1;
                path.pop_back();
            }
        }
    }

    // Main function to find paths in the maze
    vector<string> findPath(vector<vector<int>>& mat) {
        vector<string> result;

        // If the start point or the destination is blocked, return empty result
        if (mat[0][0] == 0 || mat[mat.size() - 1][mat.size() - 1] == 0) {
            return result;
        }

        // Initialize an empty path and call the recursive function
        string path = "";
        mat[0][0] = 0;  // Mark the start point as visited
        solve(mat, mat.size(), 0, 0, path, result);
        
        return result;
    }