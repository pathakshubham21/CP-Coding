#include<iostream>
#include<limits>
using namespace std;
int static dp[2001][2001];


bool IsPalondrome(string str, int start, int end)
{
    while(start<=end)
    {
        if(str[start]!=str[end])
        return false;

        start++;
        end--;
    }

    return true;
}


int palondromePartition(string str, int i, int j)
{

    if(i>=j)
    return dp[i][j]=0;

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    if(IsPalondrome(str, i,j))
    {
        return dp[i][j] = 0;
    }

    int ans = INT_MAX;


    for(int k = i;k<j;k++)
    {

        if(IsPalondrome(str, i,k))
        {
        int tempans = palondromePartition(str, k+1, j)+1;
        ans = min(ans, tempans);
        }
    }

    return dp[i][j]=ans;


}
    int minCut(string s) {

        memset(dp, -1, sizeof(dp));

        int n = s.length();
       return palondromePartition(s, 0, n-1);

        
    }


int main()
{
    string str = "leet";
    int n = 4;
    cout<<minCut(str);
}