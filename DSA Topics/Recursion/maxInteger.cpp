#include <algorithm>
class Solution {
public:

    void solve(string &num,string &result , int start,int k)
    {
        if(k==0 || start==num.length())
        {
            return;
        }
        char maxChar = *std::max_element(start + 1, num.end());

        for(int i= start+1;i<num.lenght();i++)
        {
            if(num[start]<num[i] && num[i]==maxChar)
            {
                swap(num[start],num[i]);
                if(num.compare(result)>0)
                {
                    result = num;
                }
                solve(num,result,start+1,k-1);
                swap(num[start],num[i]);


            }

        }


    }
    string maxInteger(string num, int k) {
        if(k==0)
        return num;

        string result  = num;
        solve(num,result,0,k);
        return result;
    }
};