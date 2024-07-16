// Problem statement
// You are given a string 'STR' consisting of lower and upper case characters. You need to remove the consecutive duplicates characters, and return the new string.



// Note :
// You don't have to print anything, it has already been taken care of. Just implement the given function.

string removeConsecutiveDuplicates(string str) 
{
    //Write your code here
    string result;
    if(str.length()==1)
    result = str;

    result+=str[0];
  

    for(int i=1;i<str.length();i++)
    {
        if(str[i]!=str[i-1])
        {
            result+=str[i];
        }
    }
    return result;
}