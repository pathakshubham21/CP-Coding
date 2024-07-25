// Problem statement
// Given an integer array A of size N, check if the input array can be divided in two groups G1 and G2 with following properties-

// - Sum of both group elements are equal
// - Group 1: All elements in the input, which are divisible by 5 
// - Group 2: All elements in the input, which are divisible by 3 (but not divisible by 5). 
// - Elements which are neither divisible by 5 nor by 3, can be put in either group G1 or G2 to satisfy the equal sum property. 
// Group 1 and Group 2 are allowed to be unordered and all the elements in the Array A must belong to only one of the groups.
// Return true, if array can be split according to the above rules, else return false.

// Note: You will get marks only if all the test cases are passed.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= N <= 50
// Sample Input 1 :
// 2
// 1 2
// Sample Output 1 :
// false
// Sample Input 2 :
// 3
// 1 4 3
// Sample Output 2 :
// true



#include<vector>
#include<iostream>
using namespace std;

bool splitArray_Helper(vector<int>vec, int G1Sum, int G2Sum , int index)
{
    if(index==vec.size())
    return G1Sum == G2Sum;


    bool ans = splitArray_Helper(vec, G1Sum+vec[index], G2Sum, index+1 ) || splitArray_Helper(vec, G1Sum, G2Sum+vec[index], index+1 );
    return ans;
}

bool splitArray(int *input, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */

     vector<int>G1;
     vector<int>G2;
     vector<int>vec;
     int G1Sum =0;
     int G2Sum = 0;
     int sumVec = 0;

     for(int i=0;i<size;i++)
     {
         if(input[i]%5==0)
         {
             G1.push_back(input[i]);
             G1Sum+=input[i];
         }
         else if(input[i]%5!=0 && input[i]%3==0)
         {
             G2.push_back(input[i]);
             G2Sum+=input[i];
         }
         else
         {
             vec.push_back(input[i]);
             sumVec+= input[i];
         }
     }


bool status = splitArray_Helper(vec, G1Sum, G2Sum, 0);


     if(G1Sum == G2Sum && vec.size()==0 )
     {
         return true;
     }

     else if(G1Sum == G2Sum && status)
     {
         return true;
     }
     else if (G1Sum != G2Sum && status)
     {
         return true;
     }
     else{
           return false;
     }

     


    
}
