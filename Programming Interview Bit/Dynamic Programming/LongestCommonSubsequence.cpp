/*
Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.

You need to return the length of such longest common subsequence.



Problem Constraints
1 <= |A|, |B| <= 1005



Input Format
First argument is an string A.

Second argument is an string B.



Output Format
Return the length of such longest common subsequence between string A and string B.



Example Input
Input 1:

 A = "abbcdgf"
 B = "bbadcgf"


Example Output
Output 1:

 5


Example Explanation
Explanation 1:

 The longest common subsequence is "bbcgf", which has a length of 5
 **/

int t[1006][1006];

int LCS (string a, string b, int n, int m)
{
    if (n == 0 || m == 0)
    return 0;
    
    if (t[n][m] != -1)
    return t[n][m];
    
    if (a[n - 1] == b[m - 1])
    return t[n][m] = 1 + LCS(a, b, n - 1, m - 1);
    
    else
    return t[n][m] = max(LCS(a, b, n - 1, m), LCS(a, b, n, m - 1));
}

int Solution::solve(string A, string B) {
    
    int n = A.size();
    int m = B.size();
    
    memset (t, -1, sizeof(t));
    
    return LCS(A, B, n, m);
    
}
