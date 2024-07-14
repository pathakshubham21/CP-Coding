// Problem statement
// You have been given a random integer array/list(ARR) of size N. You are required to find and return the second 
// largest element present in the array/list.
int findSecondLargest(int arr[], int n)
{

    int first = -1000;
    int second;
    second = first;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>first)
        {
            second = first;
            first = arr[i];
        }
        else if(arr[i]>second&&arr[i]<first)
        {
            second = arr[i];
        }
    }
    return second;
    //Write your code here
}