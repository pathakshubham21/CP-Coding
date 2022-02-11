#include<iostream>
#include<vector>
using namespace std;
void permutation(vector<int>&vec, vector<vector<int> >&result, int itr)
{

    if(itr>=vec.size())
    {
        result.push_back(vec);
        return;
    }

    for(int i=itr;i<vec.size();i++)
    {
        swap(vec[itr],vec[i]);
        permutation(vec,result,itr+1);
        swap(vec[i],vec[itr]);  //Backtracking to the previous input 
    }

}

int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }

    vector<vector<int> > result;

    permutation(vec,result,0);

    for(int i=0;i<vec.size();i++)  // Printing the result array (All possible permutaion)
    {
        for(int j=0;j<result.size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;





}