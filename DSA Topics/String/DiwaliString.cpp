#include<iostream>
using namespace std;


int main()
{
    string str;

    cout<<"Enter the String: ";
    cin>>str;

    int n = str.size();
    int i=0;
    int j = n-1;

   reverse(str.begin(), str.end());

    cout<<"Reverse of String is: "<<str;

}