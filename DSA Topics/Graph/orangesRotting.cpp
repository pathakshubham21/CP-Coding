//    You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.


    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();



        vector<pair<int,int>>direction {{-1,0},{1,0},{0,-1},{0,1}};

        // {{row,col},time}
        queue<pair<pair<int,int>,int>> q;
        int fresh_orange = 0;



        vector<vector<int>>visited(n, vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j] =2;
                }
                else if(grid[i][j] == 1)
                {
                    fresh_orange++;
                }

            }
        }

        int result_time = 0;
        int rotten_orenages = 0;

        while(!q.empty())
        {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();

            result_time = max(result_time,time);

            for(int i =0;i<4;i++)
            {
                int neighbour_row = row + direction[i].first;
                int neighbour_col = col + direction[i].second;

                if(neighbour_row>=0 && neighbour_row<n && neighbour_col >=0 && neighbour_col<m && visited[neighbour_row][neighbour_col]!=2 && grid[neighbour_row][neighbour_col]==1)
                {
                    grid[neighbour_row][neighbour_col] = 2;
                    visited[neighbour_row][neighbour_col] = 2;
                    rotten_orenages++;
                    q.push({{neighbour_row,neighbour_col},time+1});

                }
            }

            

        }

        if(rotten_orenages!=fresh_orange)
            {
            return -1;
            }
            else
            {
                return result_time;
            }

        
    }