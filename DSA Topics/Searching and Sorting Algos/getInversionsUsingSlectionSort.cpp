// Problem statement
// You have a list of numbers that are not in order. You want to find the sum of the differences between the indices of pairs of numbers that are in the wrong order. A pair of numbers is considered to be in the wrong order if the smaller number comes after the larger number in the list.

// Example:
// Input: ‘N’ = 5 
// ‘A’ = [3, 2, 11, 5, 1]

// Output: 6


int getInversions(int arr[], int n)
{

    int min = 10000;
    int sum = 0;
    int index = 0;


    for(int i=0;i<n-1;i++)
    {   
        min = arr[i];
        index = i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<min)
            {
                min = arr[j];
                index = j;
            }
        }
        sum = sum + (index-i);
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
        
    }
    // 1,2,11,5,3

    return sum;
    //Write your code here
}