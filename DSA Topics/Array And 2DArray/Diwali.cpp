#include<iostream>
using namespace std;

int main()
{


    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    int arr[n];


    cout<<"Enter the elements in Array: ";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int sum = 0;

    for(int i=0;i<n;i++)
    {
        sum+= arr[i];
    }

    cout<<"Sum of array is : "<<sum;

    return 0;
}