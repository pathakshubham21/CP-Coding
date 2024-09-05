//   An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

// Examples:

// Input: image = {{1,1,1},{1,1,0},{1,0,1}},
// sr = 1, sc = 1, newColor = 2.
// Output: {{2,2,2},{2,2,0},{2,0,1}}
// Explanation: From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected by a path of the same color as the starting pixel are colored with the new color.Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
 
// Expected Time Compelxity: O(n*m)
// Expected Space Complexity: O(n*m)
 

// Constraints:
// 1 <= n <= m <= 100
// 0 <= pixel values <= 10
// 0 <= sr <= (n-1)
// 0 <= sc <= (m-1)

    bool fill_neighbour_Color(int neighbour_row, int neighbour_col, vector<vector<int>>&result, int n, int m, int oldColor, int newColor) {
    // Check if the neighbor is within bounds and has the old color
    if (neighbour_row >= 0 && neighbour_row < n && neighbour_col >= 0 && neighbour_col < m && result[neighbour_row][neighbour_col] == oldColor) {
        result[neighbour_row][neighbour_col] = newColor;
        return true;
    }
    return false;
}

void bfs(vector<vector<int>>& image, int row, int col, int newColor, vector<vector<int>>& result, vector<pair<int, int>>& direction) {
    int n = image.size();
    int m = image[0].size();
    queue<pair<int, int>> q;
    q.push({row, col});
    int oldColor = image[row][col];

    // Mark the starting cell with the new color
    result[row][col] = newColor;

    while (!q.empty()) {
        pair<int, int> Front_node = q.front();
        q.pop();
        int current_row = Front_node.first;
        int current_col = Front_node.second;

        // Check all four possible directions
        for (int i = 0; i < 4; i++) {
            int neighbour_row = current_row + direction[i].first;
            int neighbour_col = current_col + direction[i].second;

            if (fill_neighbour_Color(neighbour_row, neighbour_col, result, n, m, oldColor, newColor)) {
                q.push({neighbour_row, neighbour_col});
            }
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int n = image.size();
    int m = image[0].size();

    // Initialize the result array with the original image values
    vector<vector<int>> result = image;

    // Define the 4 possible movement directions
    vector<pair<int, int>> direction = {
        {-1, 0},  // Up
        {1, 0},   // Down
        {0, -1},  // Left
        {0, 1}    // Right
    };

    // Call BFS to perform the flood fill
    if (image[sr][sc] != newColor) {
        bfs(image, sr, sc, newColor, result, direction);
    }

    return result;
}