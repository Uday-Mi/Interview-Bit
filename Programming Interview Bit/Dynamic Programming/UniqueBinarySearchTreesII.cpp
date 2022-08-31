/*
Given an integer A, how many structurally unique BST’s (binary search trees) exist that can store values 1…A?

Input Format:

The first and the only argument of input contains the integer, A.
Output Format:

Return an integer, representing the answer asked in problem statement.
Constraints:

1 <= A <= 18
Example:

Input 1:
    A = 3

Output 1:
    5

Explanation 1:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
**/

//RECURSION + MEMOIZATION

int t[19][19];

int solve (int start, int end)
{
    if (start > end)
    return 0;
    
    if (start == end)
    return 1;
    
    if (t[start][end] != -1)
    return t[start][end];
    
    int left = 1;
    int right = 1;
    int ans = 0;
    
    for (int i = start; i <= end; i++)
    {
        if (t[start][i - 1] != -1)
        left = t[start][i - 1];
        else
        left = solve(start, i - 1);
        
        if (left <= 0)
        left = 1;
        
        if (t[i + 1][end] != -1)
        right = t[i + 1][end];
        else
        right = solve(i + 1, end);
        
        if (right <= 0)
        right = 1;
        
        ans = ans + (left * right);
    }
    
    return t[start][end] = ans;
}

int Solution::numTrees(int A) {
    
    memset(t, -1, sizeof(t));
    
    return solve(0, A - 1);
    
}

//DYNAMIC PROGRAMMING

int Solution::numTrees(int A) {
  
    int t[A + 1];
    
    int sum = 0;
    
    t[0] = 1;
    t[1] = 1;
    
    for (int i = 2; i <= A; i++)
    {
        sum = 0;
        for (int j = 1; j <= i; j++)
        {
            sum = sum + t[j - 1] * t[i - j];
        }
        t[i] = sum;
    }
    
    return t[A];
}
