class Solution {
public:
// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

void solve(string &s,int index,vector<string>&temp,vector<string>&result,unordered_map<string,int> &mp  )
{
    if(index==s.length())
    {
        for(int i=0;i<temp.size();i++)
        {
            result.push_back(temp[i]);
        }
        return;
    }

    string word;
    for(int i=index;i<s.length();i++)
    {
        word+=s[i];
        if(mp.find(word)!=mp.end())
        {
            temp.push_back(word);
            solve(s,i+1,temp,result,mp);
            temp.pop_back();
        }
    }
}
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_map<string,int>mp;
        for(int i=0;i<wordDict.size();i++)
        {
            mp[wordDict[i]]=1;
        }
        vector<string>result;
        vector<string>temp;
        solve(s,0,temp,result,mp);

        if(result.size()==0)
        return false;

        for(int i=0;i<result.size();i++)
        {
           
            if(mp[result[i]]!=1)
            return false;
        }

        return true;

        
    }
};