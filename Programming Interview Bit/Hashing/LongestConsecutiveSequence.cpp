/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example: 

Given [100, 4, 200, 1, 3, 2],

The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
**/

#include <bitset>

int Solution::longestConsecutive(const vector<int> &A) {
    
    int n = A.size();
    
    int mi = INT_MAX;
    
    for (int  i = 0; i < n; i++)
    {
        mi = min(mi, A[i]);
    }
    
    if (mi >= 0)
    mi = 0;
    
    mi = mi * -1;
    
    bitset <10000000> b;
    
    for (int i = 0; i < n; i++)
    {
        b[A[i] + mi] = 1;
    }
    
    int c = 0;
    int mn = INT_MIN;
    
    for (int i = 0 ; i < 10000000; i++)
    {
        if (b[i] == 1)
        c++;
        
        if (b[i] == 0)
        c = 0;
                
        mn = max(mn, c);
    }
    
    return mn;
    
}
