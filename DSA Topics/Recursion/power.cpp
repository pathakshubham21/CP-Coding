// Problem statement
// Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.

// Do this recursively.

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= x <= 30
// 0 <= n <= 30
// Sample Input 1 :
//  3 4
// Sample Output 1 :
// 81
// Sample Input 2 :
//  2 5
// Sample Output 2 :
// 32

int power(int x, int n) {
  if(n<1)
  return 1;

  int res = power(x,  n-1);
  return x*res;
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */

}