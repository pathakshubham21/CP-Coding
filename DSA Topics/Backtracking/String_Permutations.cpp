#include<iostream>
#include<vector>
using namespace std;
void helper(string s, int idx,vector<string> &res)
    {
        if(idx==s.length()-1)
        {
            res.push_back(s);
            return;
            
        } 

    for(int i= idx;i<s.length();i++)
    {
        swap(s[i],s[idx]);
        helper(s,idx+1,res);
        swap(s[i],s[idx]);
        
    }

}

vector<string> permutation(string S)
{
        
    vector<string>res;
    helper(S,0,res);
    return res;
}
int main()
{
    string s;
    cin>>s;
    vector<string>res;
    res = permutation(s);

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;=
}