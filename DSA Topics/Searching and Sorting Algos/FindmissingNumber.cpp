// Problem statement
// You have been given an array/list. Your task in to return the missing number. Array contains the distinct element form (0,N), both are inclusive. Missing number is the number that is not present in the array.

// Input: ‘N’ = 4 
// ‘A’ = [3, 1, 0, 4]

// Output: 2

// Explanation: For nums = [3, 1, 0, 4],
// The array does not contain the element '2' in the range of [0,4]. So, the answer would be 2.

int missingNumber(int arr[], int n)
{
    int sum = 0;
    int sumOfArray=0;
    sum = (n*(n+1))/2;

    for(int i=0;i<n;i++)
    {
        sumOfArray +=arr[i];
    }

    return sum-sumOfArray;
    //Write your code here
    
}