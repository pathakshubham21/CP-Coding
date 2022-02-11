#include<iostream>
#include<vector>
using namespace std;
void winner(vector<int>&vec,int k,int idx)
{
    if(vec.size()==1)
    {
        cout<<"Winner Person: "<<vec[0]<<endl;
        return;
    }
    idx = (idx+k)%vec.size();
    vec.erase(vec.begin()+idx);
    winner(vec,k,idx);
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
        vec[i]= i+1;
    }
    winner(vec,k-1,0);
    return 0;  
}



