#include<iostream>
using namespace std;
string helper(string str,int idx, string result_str,char ch)
{
    if(idx==str.length())
    {
        for(int i=0;i<=str.length()-result_str.length();i++)
        {
            result_str+=ch;
        }
        return result_str;
    }
    if(str[idx]!=ch)
    {
        result_str+=str[idx];
    }
    return helper(str,idx+1,result_str,ch);
}
int main()
{
    string str;
    char ch;
    cin>>str>>ch;
    string result_str ="";
    result_str = helper(str,0,result_str,ch);
    cout<<result_str;
    return 0;
}