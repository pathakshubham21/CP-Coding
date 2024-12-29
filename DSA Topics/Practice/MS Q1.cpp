#include <iostream>
using namespace std;

int main() {
    // you can write to stdout for debugging purposes, e.g.
    
    int n = 6;

    int arr[] =  {1,0,0,1,0,1};
    // int arr[] =  {1,1,1,0,0,1};

    int ans = 0;

    int k =0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==1 && arr[i+1]!=1 && i!=n-1)
        {
          k = i;
          int start = i;
          int end = i+1;

          while(end<n)
          {
              if(arr[end]==1)
              {
                  arr[k++] =1;
                  arr[end] = 0;
                  ans+= (end-start)-1;
                  start = end+1;
                  end = start+1;
              }
              else {
              end++;

              }

          }
        }
    }

    

    cout<<ans<<endl;




}
