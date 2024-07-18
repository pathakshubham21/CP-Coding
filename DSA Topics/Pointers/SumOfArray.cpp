// Problem statement
// Given an array of length N, you need to find and return the sum of all elements of the array using the concept of pointer arithmetic and pointers.

int sum(int *ar , int n)
{
    //write your code here
    int sum = 0;

    for(int i=0;i<n;i++)
    {
        sum+=*(ar+i);
    }
    return sum;
}