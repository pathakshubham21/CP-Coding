#include<iostream>
using namespace std;
int main()
{
    int n,item;
    cin>>n>>item;
    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int first =-1;
    int last = -1;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==item)
        {
            if(first==-1)
            first = i;
            else
            last = i;
        }
    }

    cout<<first<<" "<<last;
    return 0;
}