/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.
**/

int Solution::firstMissingPositive(vector<int> &A) {
    
    int n = A.size();
    sort(A.begin(), A.end());
    int j;
    int i = 0;
    
    for (i = 0; i < n; i++)
    {
        if (A[i] > 0)
        {
            if (A[i] > 1)
            return 1;
            for (j = i; j < n - 1; j++)
            {
                int a = A[j + 1] - A[j];
                if (a > 1)
                {
                    A[j]++;
                    return A[j];
                }
            }
            int a = A[n - 1] + 1;
            return a;
        }
    }
    
    if (i == n)
    return 1;
    
}
