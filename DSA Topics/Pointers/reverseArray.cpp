// Problem statement
// Given an array ar of n integers, reverse the elements of the array by using the concept of pointers.

void reverse(int *ar,int n)
{
	//write your code here

	int i=0,j=n-1;
	int temp;

	while(i<j)
	{
		temp = ar[i];
		ar[i] = ar[j];
		ar[j] = temp;
		i++;
		j--;
	}
}