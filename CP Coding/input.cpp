#include<iostream>
#include<vector>
using namespace std;

bool two_sum(vector<int>vec,int itr, int n, int sum,int result)
{
   if(itr==n)
   return false;
   if(result == sum)
   {
       cout<<"itr Value = "<<itr-1<<endl;
   return true;
   }
   if(result<sum && vec[itr]!=sum)
   return two_sum(vec,itr+1,n,sum,result+vec[itr]) || two_sum(vec,itr+1,n,sum,result);
   else 
   return two_sum(vec,itr+1,n,sum,result);

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
    cout<<two_sum(vec,0,n,sum,0);


}
