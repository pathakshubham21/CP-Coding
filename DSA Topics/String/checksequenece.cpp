// Problem statement
// Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).

// Return true or false.

// Do it recursively.

// E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// abchjsgsuohhdhyrikkknddg
// coding
// Sample Output 1 :
// true
// Sample Input 2 :
// abcde
// aeb
// Sample Output 2 :
// false

#include<cstring>

bool checksequenece(char large[] , char*small) {


if(small[0]=='\0')
return true;
if(large[0]=='\0')
return false;

if(small[0]==large[0])
{
    checksequenece(large+1,small+1);
}
else{
    checksequenece(large+1,small);
}


}