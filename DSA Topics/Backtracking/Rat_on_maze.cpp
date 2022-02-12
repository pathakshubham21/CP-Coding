#include<iostream>
#include<vector>
using namespace std;

class RAT_ON_MAZE
{
    public:
    
    bool rat_on_maze(vector<vector<int> >&maze, vector<vector<int> >&result, int n,int row,int col)
    {
        if(row==n-1 && col == n-1)
        {
            if(maze[row][col]==1)
            {

                result[row][col] =1;
                
                
                return true;
            }
            else
            {
                result[row][col] =0; 
                
                return false;

            }
        }
        if(isSafe(maze,row,col,n))
        {
            result[row][col] = 1;
            if(rat_on_maze(maze,result,n,row+1,col))
            {
                return true;
            }
            if(rat_on_maze(maze,result,n,row,col+1))
            {
                
                return true;
            }
            result[row][col] = 0;   // Backtracking
            return false;
        }
        return false;

    }
    bool isSafe(vector<vector<int> >&maze, int row, int col, int n)
    {
        if(row<0 || col<0 || row==n || col==n || maze[row][col]==0)
        return false;
        else
        return true;

    }
};

int main()
{
    int n;
    cin>>n;
    RAT_ON_MAZE obj;
    vector<vector<int> >maze(n, vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }
    vector<vector<int> >result(n,vector<int>(n,0));
    obj.rat_on_maze(maze,result,n,0,0);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}

/*
N = 4
maze[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
*/
        