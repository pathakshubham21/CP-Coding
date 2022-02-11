#include<iostream>
using namespace std;

void helper(string str,char ch,int idx)
{

    static int first =-1;
    static int last =-1;
    if(idx==str.length())
    {
         cout<<first<<" "<<last;
        return;
    }

    if(str[idx]==ch)
    {
        if(first==-1)
        {
            first = idx;
        }
        else
        {
            last = idx;
        }
    }

    helper(str,ch,idx+1);
}

int main()
{
    string str;
    char ch;

    cin>>str>>ch;
    helper(str,ch,0);
    return 0;
   


}