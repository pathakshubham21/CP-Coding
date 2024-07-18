
// Problem statement
// Given an array of n integers, find and return the pointer type reference to the highest element of the array. For example if the array is "1 2 3 4 5", you have to return the pointer type variable holding the address of "5".

#include<bits/stdc++.h>
using namespace std;
int* findmax(int *ar,int n)
{
    if (n == 0) return nullptr; // Check for empty array

    int *high = ar;
    int max = ar[0];

    for (int i = 1; i < n; i++) { // Start from the second element
        if (ar[i] > max) {
            max = ar[i];
            high = &ar[i];
        }
    }

    return high;
    //write your code here
}