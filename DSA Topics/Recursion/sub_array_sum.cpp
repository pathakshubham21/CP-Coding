#include<iostream>
#include<vector>

// 8 3 4 5 7
using namespace std;
vwctor<int> helper(vector<int>vec,int n)
{
    unordreed
   if(temp==sum)
   {
       return true;
   }
   if(n<0||sum==0|| temp>sum)
   return false;

   return helper(vec,n-1,sum,temp+vec[n]) || helper(vec,n-1,sum,temp);

}

int main()
{
    int n;
    cin>>n;
    int sum;
    cin>>sum;
    vector<int>vec;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;
        vec.push_back(data);
    }
    int temp= 0;

    cout<<helper(vec,n-1,sum,temp);
}