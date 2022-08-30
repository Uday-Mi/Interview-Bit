/*
Given an integer array A containing N integers.

You need to divide the array A into two subsets S1 and S2 such that the absolute difference between their sums is minimum.

Find and return this minimum possible absolute difference.

NOTE:

Subsets can contain elements from A in any order (not necessary to be contiguous).
Each element of A should belong to any one subset S1 or S2, not both.
It may be possible that one subset remains empty.


Problem Constraints
1 <= N <= 100

1 <= A[i] <= 100



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the minimum possible difference among the sums of two subsets.



Example Input
Input 1:

 A = [1, 6, 11, 5]


Example Output
Output 1:

 1


Example Explanation
Explanation 1:

 Subset1 = {1, 5, 6}, sum of Subset1 = 12
 Subset2 = {11}, sum of Subset2 = 11
**/

int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        sum = sum + A[i];
    }
    
    int t[n + 1][sum + 1];
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            t[i][j] = false;
            if (j == 0)
            t[i][j] = true;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (A[i - 1] <= j)
            t[i][j] = t[i - 1][j] || t[i - 1][j - A[i - 1]];
            else
            t[i][j] = t[i - 1][j];
        }
    }
    
    vector <int> v;
    
    for (int i = 0; i <= sum / 2; i++)
    {
        if (t[n][i] == true)
        v.push_back(i);
    }
    
    int mn = INT_MAX;
    
    for (int i = 0; i < v.size(); i++)
    {
        mn = min(mn, sum - 2 * v[i]);
    }
    
    return mn;
    
}
