// minimum-deletions-to-make-string-balanced
//You are given a string s consisting only of characters 'a' and 'b'​​​​.

// You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

// Return the minimum number of deletions needed to make s balanced.

 

// Example 1:

// Input: s = "aababbab"
// Output: 2
// Explanation: You can either:
// Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
// Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
// Example 2:

// Input: s = "bbaaaaabb"
// Output: 2
// Explanation: The only solution is to delete the first two characters.
 

// Constraints:

// 1 <= s.length <= 105
// s[i] is 'a' or 'b'​​.

class Solution {
public:
    int minimumDeletions(string s) {
        int a_count[s.length()];
        int b_count[s.length()];
        int count_a = 0;
        int count_b = 0;
        int min_del = INT_MAX;
        for(int i=0; i<s.length();i++){
            if (s[i]=='a'){
                count_a++;
            }
            a_count[i] = count_a;
        }
        for(int i=s.length()-1;i>=0;i--){
            if (s[i]=='b')
            count_b++;
            b_count[i] = count_b;
        }

        for(int i =0;i<s.length();i++){
            int sum = a_count[i]+b_count[i];
            if (min_del > (s.length()-sum))
            min_del = s.length()-sum;
        
        }
        return min_del;
        
        
    }
};


// Flow Up - Return the index of all deleted characters in the string.
// Find the index where the first largest substring appears, then determine deletions of 'a' and 'b' based on the minimum count of both.
// If 'a' needs to be deleted, remove all 'a' characters after the found index.
// If 'b' needs to be deleted, remove all 'b' characters before the found index.
