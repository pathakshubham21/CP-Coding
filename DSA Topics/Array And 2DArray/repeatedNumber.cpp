// You are given a read only array of n integers from 1 to n.

// Each integer appears exactly once except A which appears twice and B which is missing.

// Return A and B.

// Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// Note that in your output A should precede B.

// Example:

// Input:[3 1 2 5 3] 

// Output:[3, 4] 

// A = 3, B = 4


vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int hash[A.size()+1] = {0};
    
    for(int i=0;i<A.size();i++)
    {
        hash[A[i]]++;
    }
    int count =0;
    int missing = -1;
    int repeating  = -1;
    
    for(int i=1;i<=A.size()+1;i++)
    {
        if(hash[i]==0)
        {
            missing = i;
        }
        else if(hash[i]==2)
        {
            repeating = i;
        }
        if(missing!=-1 && repeating!=-1)
        {
            return {repeating,missing};
        }
    }
    
    return {repeating,missing};
    // return {repeating,missing};
}
