#include<iostream>
#include<vector>
using namespace std;


void GenratePranthasisHelper(int open, int close, vector<string>&result, string output)
{

    if(open==0 && close ==0)
    {
        result.push_back(output);
        return;
    }

    if(open!=0)
    {
        output += "(";
        GenratePranthasisHelper(open-1, close, result, output);
        output.pop_back();
    }
    if(close>open)
    {
        output += ")";
        GenratePranthasisHelper(open, close-1, result, output);
        output.pop_back();

    }

    

}


void GenratePranthasis(int n)
{

    if(n==0)
    {
        return;
    }

    int open  = n;
    int close = n;
    string output = "";
    vector<string>result;
    GenratePranthasisHelper(open, close, result, output);

    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }

    return;


}

int main()
{

    int n = 3;
    GenratePranthasis(n);
    return 0;


}

