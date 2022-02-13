#include<iostream>
#include<vector>
using namespace std;
vector<int>inter;
class N_Queen
{
    public:

    void N_queen_fun(vector<vector<int> >&result,  vector<vector<int> >& total_sol, int row, int n)
    {
        if(row==n)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(result[i][j]==1)
                    {
                        inter.push_back(j+1);
                    }
                }
            }   
            total_sol.push_back(inter);
            inter.erase(inter.begin(),inter.end());
            
            return;    
        }

        for(int col = 0; col < n; col++)
        {

        if(isSafe(result,row,col,n))
        {
            result[row][col] = 1;
            
            N_queen_fun(result,total_sol,row+1,n);
            
            result[row][col] = 0;
        }
        }

    }
    bool isSafe(vector<vector<int> >&result,int row, int col, int n)
    {
        if(row<0 || col<0 || row>=n || col>=n || result[row][col]==1)
        {
            return false;
        }
        for(int i=0;i<n;i++)     // row check
        {
            if(result[row][i] == 1)
            {
                return false;
            }
        }
        for(int i=0;i<n;i++)  // col check
        {
            if(result[i][col] == 1)
            {
                return false;
            }
        }
        for(int i=row, j=col; i<n && j<n; i++,j++) // Right bottom digonal check
        {
            if(result[i][j]==1)
            return false;

        }
        for(int i=row, j=col; i<n && j>=0; i++,j--) // Left Bottom digonal check
        {
            if(result[i][j]==1)
            {
            return false;
            }

        }
        for(int i=row, j=col; i>=0 && j<n; i--,j++) // Right up digonal check
        {
            if(result[i][j]==1)
            return false;

        }
        for(int i=row, j=col; i>=0 && j>=0; i--,j--) // Left up digonal check
        {
            if(result[i][j]==1)
            return false;

        }

        return true;


    }

};

int main()
{
    int n;
    cin>>n;
    vector<vector<int> >result(n,vector<int>(n,0));
    vector<vector<int> >total_sol;

    N_Queen obj;
    obj.N_queen_fun(result,total_sol,0,n);
    cout<<"Total Possible Solution: "<<total_sol.size()<<endl;
    for(int i=0;i<total_sol.size();i++)
    {
        for(int j=0;j<total_sol[i].size();j++)
        {
            cout<<total_sol[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}