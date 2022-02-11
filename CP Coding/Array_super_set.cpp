#include<iostream>
#include<vector>
using namespace std;
void Super_set(vector<int>vec, vector<vector<int> >&result, vector<int>inter, int itr)
{

    if(itr>=vec.size())
    {
        result.push_back(inter);
        return;
    }
    else
    {

        Super_set(vec,result,inter,itr+1);
        inter.push_back(vec[itr]);
        Super_set(vec,result,inter,itr+1);
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

    vector<vector<int> >result;
    vector<int>inter;
    Super_set(vec,result,inter,0);

    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }


}