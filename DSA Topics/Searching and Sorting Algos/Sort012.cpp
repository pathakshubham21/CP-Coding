// Problem statement
// You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s. Write a solution to sort this array/list in a 'single scan'.

// 'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.

// Note:
// You need to change in the given array/list itself. Hence, no need to return or print anything. 


void sort012(int arr[], int n)
{
    int count1=0,count2=0,count0=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            count0++;
        }
        else if(arr[i]==1)
        {
            count1++;
        }
        else{
            count2++;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(count0>0)
        {
            arr[i]=0;
            count0--;
        }
        else if(count1>0)
        {
            arr[i]=1;
            count1--;
        }
        else{
            arr[i]=2;
        }
    }
    //Write your code here
}