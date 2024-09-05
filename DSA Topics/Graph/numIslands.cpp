Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Examples:

Input: grid = [[0,1],[1,0],[1,1],[1,0]]
Output: 1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]
Output: 2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands :- one is colored in blue and other in orange.
Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
0 ≤ grid[i][j] ≤ 1


  void bfs(vector<vector<char>>&grid, vector<vector<int>>&visited, int row, int col)
  {
      queue<pair<int,int>>q;
      int n = grid.size();
      int m = grid[0].size();
      
      q.push({row,col});
    //   visited[grid[row][col]] =1;
      
      
      while(!q.empty())
      {
          pair<int,int> Front_node = q.front();
          int row= Front_node.first;
          int col = Front_node.second;
          q.pop();
          for(int deltarow = -1;deltarow<=1;deltarow++)
          {
              for(int deltacol = -1;deltacol <=1;deltacol++)
              {
                  int neighbour_row = row+deltarow;
                  int neighbour_col = col +deltacol;
                  if(neighbour_row>=0 && neighbour_row <n && neighbour_col>=0 && neighbour_col<m
                  && grid[neighbour_row][neighbour_col]=='1' && visited[neighbour_row][neighbour_col]!=1)
                  {
                     visited[neighbour_row][neighbour_col] = 1;
                     q.push({neighbour_row ,neighbour_col});
                  }
              }
          }
      }
      
      return;
      
      
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n= grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>visited(n, vector<int>(m,0));
        int count = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j= 0;j<m;j++)
            {
                if(visited[i][j]==0 && grid[i][j]=='1')
                {
                    bfs(grid, visited, i, j);
                    visited[i][j] =1;
                    count++;
                }
            }
        }
        return count;
    }