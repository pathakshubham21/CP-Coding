// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

class Solution {
public:

    bool Ispalindrome(string str)
    {
        if(str.length()==1)
        return true;

        int l = 0;
        int r = str.length()-1;
        while(l<=r)
        {
            if(str[l]!=str[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solve(string s,int index,vector<string>&vec,vector<vector<string>>&result)
    {
        if(index==s.length())
        {
            result.push_back(vec);
            return;
        }
        string palindromic_str;
        for(int i=index;i<s.length();i++)
        {
            palindromic_str+=s[i];
            if(Ispalindrome(palindromic_str))
            {
                vec.push_back(palindromic_str);
                solve(s,i+1,vec,result);
                vec.pop_back();
            }
        }

    }
    // partiction arrey in two equal part
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        if(s.length()==0)
        return result;

        vector<string>vec;
        solve(s,0,vec,result);
        return result;

        
    }
};