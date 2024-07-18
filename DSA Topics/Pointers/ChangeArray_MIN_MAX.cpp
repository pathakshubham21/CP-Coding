// Problem statement
// Given an array ar of n integers, find the minimum and maximum value in the array and store their addresses in separate pointer variables. Then, modify the values at the addresses pointed by these pointers setting the minimum value to 0 and maximum value to 100.

#include<math.h>
#include <climits>
void modify(int *ar,int n)
{
int min = INT_MAX, max = INT_MIN;
    int *pmin = nullptr, *pmax = nullptr;

    // Find the minimum and maximum values and their addresses
    for (int i = 0; i < n; i++) {
        if (ar[i] > max) {
            max = ar[i];
            pmax = &ar[i];
        }
        if (ar[i] < min) {
            min = ar[i];
            pmin = &ar[i];
        }
    }

    // Modify the values at the addresses pointed by pmin and pmax
    if (pmin != nullptr) {
        *pmin = 0;
    }
    if (pmax != nullptr) {
        *pmax = 100;
    }
}