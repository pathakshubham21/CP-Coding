#include<iostream>
using namespace std;
void altTab(int input1,int input2,int *input3)
{
    int res[input1];

    res[0]= input3[input2-1];

   int i=0;
   int j=1;
   while(i<input1)
   {
       if(i!=input2-1)
       {
           res[j]=input3[i];
           j++;
       }
       i++;
   }
   for(int i=0;i<input1;i++)
   {
       cout<<res[i]<<" ";
   }
return;


}


int main()
{

int n;
cin>>n;
int tab;
cin>>tab;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
int result[n];
altTab(n,tab,arr);



}