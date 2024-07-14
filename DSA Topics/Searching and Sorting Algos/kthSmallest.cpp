// Problem statement
// You have been given an array/list and a number k. You have to find the kth smallest number.

// Example:
// Input: ‘N’ = 5 , 'k' = 2
// ‘A’ = [3, 2, 11, 5, 1]

// Output: 2

// Explanation: For nums = [3, 2, 11, 5, 1],
// In the given array, smallest element is 1 and 2nd smallest element is 2 and the value of k is 2. So, our output will be 2.



int kthSmallest(int arr[], int n, int k)
{

    for(int i=0;i<n;i++)
    {
        for(int j= 0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    return arr[k-1];
    //Write your code here
}