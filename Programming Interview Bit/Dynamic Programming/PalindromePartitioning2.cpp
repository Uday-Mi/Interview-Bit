/*
Given a string A, partition A such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of A.



Input Format:

The first and the only argument contains the string A.
Output Format:

Return an integer, representing the answer as described in the problem statement.
Constraints:

1 <= length(A) <= 501
Examples:

Input 1:
    A = "aba"

Output 1:
    0

Explanation 1:
    "aba" is already a palindrome, so no cuts are needed.

Input 2:
    A = "aab"
    
Output 2:
    1

Explanation 2:
    Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
    **/

int t[502][502];

bool isPalindrome(string str, int i, int j)
{
    if (i == j)
    return true;
    
    if (i > j)
    return true;
    
    if (str[i] != str[j])
    return false;
    
    return isPalindrome(str, i + 1, j - 1);
}

int solve (string str, int i, int j)
{
    if (i >= j)
    return 0;
    
    if (isPalindrome(str, i, j) == true)
    return 0;
    
    if (t[i][j] != -1)
    return t[i][j];
    
    int mn = INT_MAX;
    
    for (int k = i; k < j; k++)
    {
        int left;
        int right;
        
        if (t[i][k] != -1)
        left = t[i][k];
        else
        left = solve(str, i, k);
        
        if (t[k + 1][j] != -1)
        right = t[k + 1][j];
        else
        right = solve(str, k + 1, j);
        
        int temp = 1 + left + right;
        
        mn = min(mn, temp); 
    }
    
    return t[i][j] = mn;
}

int Solution::minCut(string A) {
    
    int n = A.size();
    
    memset(t, -1, sizeof(t));
    
    return solve(A, 0, n - 1);
    
}
