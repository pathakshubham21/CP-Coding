// Change in the given string itself. So no need to return or print the changed string.
// Problem statement
// Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 0 <= |S| <= 1000
// where |S| represents length of string S.
// Sample Input 1 :
// hello
// Sample Output 1:
// hel*lo
// Sample Input 2 :
// aaaa
// Sample Output 2 :
// a*a*a*a


void pairStar(char input[]) {
    // Write your code here
    if(input[0]=='\0'||input[1]=='\0')
    return;

    if(input[0]==input[1])
    {
        int index = 0;
        while(input[index]!='\0')
        {
            index++;
        }
        while(index>=1)
        {
            input[index+1]=input[index];
            index--;
        }
        input[1] = '*';
        pairStar(input+2);
    }
    else{
        pairStar(input+1);
    }

}
