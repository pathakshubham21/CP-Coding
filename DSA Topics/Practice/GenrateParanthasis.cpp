#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
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

int MinStep(int n)
{
    if (n <= 1)
    {
        return 0; // Base case: no steps needed if n <= 1
    }

    // Initialize variables to a large value (representing infinity)
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;

    // If divisible by 3, try dividing by 3
    if (n % 3 == 0)
    {
        x = 1 + MinStep(n / 3);
    }
    
    // If divisible by 2, try dividing by 2
    if (n % 2 == 0)
    {
        y = 1 + MinStep(n / 2);
    }
    
    // Always try subtracting 1
    z = 1 + MinStep(n - 1);

    // Return the minimum of all possible steps
    return min(min(x, y),z);
}

int stairs(int n)
{
    if(n==0)
    return 1;

    if(n<0)
    return 0;

  return stairs(n-1)+stairs(n-2)+stairs(n-3);
}

int coinChange(vector<int>&coins, int n, int idx)
{
    if(n==0)
    {
        return 0;
    }


        if(n>=coins[idx])
        {
            return max(coins[idx]+coinChange(coins, n-coins[idx],idx),coinChange(coins, n,idx+1) );
        }
        else{
            return coinChange(coins, n,idx+1);
        }

}
int main()
{

    int n = 5;
    // cout<<MinStep(n);

    vector<int> coins(3);
     coins[0] = 1;
     coins[1] = 2;
     coins[2] = 3;

    cout<<coinChange(coins, n , 0);

    // GenratePranthasis(n);
    return 0;


}

