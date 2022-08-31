/*
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer, representing the minimum number of steps required.
Constraints:

1 <= length(A), length(B) <= 450
Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.
**/

int t[451][451];

int solve (string s1, string s2, int m, int n)
{
    if (m == 0)
    return n;
    
    if (n == 0)
    return m;
    
    if (t[m][n] != -1)
    return t[m][n];
    
    if (s1[m - 1] == s2[n - 1])
    return t[m][n] = solve(s1, s2, m - 1, n - 1);
    
    else
    return t[m][n] = 1 + min(min(solve(s1, s2, m - 1, n - 1), solve(s1, s2, m - 1, n)), solve(s1, s2, m, n - 1));
}

int Solution::minDistance(string A, string B) {
    
    int m = A.size();
    int n = B.size();
    
    memset(t, -1, sizeof(t));
    
    return solve(A, B, m, n);
    
}
