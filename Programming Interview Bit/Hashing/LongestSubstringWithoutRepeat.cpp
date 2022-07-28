/*
Given a string, 

find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.
**/

int Solution::lengthOfLongestSubstring(string A) {
    
    int n = A.size();
    
    map <int, int> mp;
    
    int c = 0;
    int maxlen = 0;
    int p;
    
    for (int i = 0; i < n; i++)
    {
        int ch = (int) A[i];
        if (mp.find(ch) != mp.end())
        {
            p = c;
            p++;
            int v = i - mp[ch];
            c = min(v, p);
        }
        
        else
        {
            c++;
        }
        mp[ch] = i;
        maxlen = max(maxlen, c);
    }
    return maxlen;
}
