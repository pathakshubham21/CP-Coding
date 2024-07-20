// Problem statement
// Given a string S (that can contain multiple words), you need to find the word which has minimum length.

// Note : If multiple words are of same length, then answer will be first minimum length word in the string. Words are seperated by single space only.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= Length of String S <= 10^5

// Sample Input 1 :
// this is test string
// Sample Output 1 :
// is
// Sample Input 2 :
// abc de ghihjk a uvw h j
// Sample Output 2 :
// a

/* input - Input String
*  output - Save the result in the output array (passed as argument). You don’t have to 
*  print or return the result
*/
#include<cstring>
#include<iostream>
#include<climits>
#include<string.h>
using namespace std;
void minLengthWord(char input[], char output[]){
		
	// Write your code here	

	int n= strlen(input);
	if(n==1)
	{
		cout<<input[0];
		return;
	}
	char temp[n];
	int min = INT_MAX;
	int start =0;
   int minLength =0;
   int WordEndIndex = 0;
	for(int i=0;i<=n;i++)
	{
		if(input[i]==' '||input[i]=='\0')
		{
			if(minLength<min)
			{
				WordEndIndex = start;
				min = minLength;	
			}
			minLength =0;
			start = i+1;

                }

        minLength++;

        }

minLength++;
while(minLength--)
{
	cout<<input[WordEndIndex++];
}



	return;







}


