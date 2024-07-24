// Problem statement
// You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.

// Note :
// Input arrays/lists can contain duplicate elements.

// The intersection elements printed would be in ascending order.



#include<unordered_map>
void intersection(int *arr1, int *arr2, int n, int m) 
{

// Space complecity =  O(n+m) and Time complecity = O(n+m)   

    unordered_map<int,int>mp1;
    unordered_map<int,int>mp2;
    for(int i=0;i<n;i++)
    {
        mp1[arr1[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        mp2[arr2[i]]++;
    }
    
    if(n<m)
    {
       for(int i =0;i<n;i++)
       {
           sort(arr1,arr1+n);
           if(mp2[arr1[i]]!=0)
           {
               cout<<arr1[i]<<" ";
               mp2[arr1[i]]--;
           }
       }
    }
    else
    {
        sort(arr2,arr2+m);
         for(int i =0;i<m;i++)
       {
           if(mp1[arr2[i]]!=0)
           {
               cout<<arr2[i]<<" ";
               mp1[arr2[i]]--;
           }
       }
    }
    //Write your code here


// Space complecity =  n(logn) and Time complecity = max(O(nlogn) , O(mlonm) )  
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    int i = 0, j = 0;
    
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
}