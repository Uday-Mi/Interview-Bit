/*
Find the longest increasing subsequence of a given array of integers, A.

In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and in which the subsequence is as long as possible. 

This subsequence is not necessarily contiguous, or unique.

In this case, we only care about the length of the longest increasing subsequence.



Input Format:

The first and the only argument is an integer array A.
Output Format:

Return an integer representing the length of the longest increasing subsequence.
Constraints:

1 <= length(A) <= 2500
1 <= A[i] <= 2000
Example :

Input 1:
    A = [1, 2, 1, 5]

Output 1:
    3
    
Explanation 1:
    The sequence : [1, 2, 5]

Input 2:
    A = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
    
Output 2:
    6

Explanation 2:
    The sequence : [0, 2, 6, 9, 13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15]
    **/

int Solution::lis(const vector<int> &A) {
    
    int n = A.size();
    
    vector <int> t(n, 0);
    
    t[0] = 1;
    
    for (int i = 1; i < n; i++)
    {
        t[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            t[i] = max(t[i], 1 + t[j]);
        }
    }
    
    int mx = INT_MIN;
    
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, t[i]);
    }
    
    return mx;
    
}
