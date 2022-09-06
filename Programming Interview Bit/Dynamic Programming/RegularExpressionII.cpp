/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.

'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:

int isMatch(const char *s, const char *p)
Some examples:

isMatch("aa","a") → 0
isMatch("aa","aa") → 1
isMatch("aaa","aa") → 0
isMatch("aa", "a*") → 1
isMatch("aa", ".*") → 1
isMatch("ab", ".*") → 1
isMatch("aab", "c*a*b") → 1
Return 0 / 1 ( 0 for false, 1 for true ) for this problem
**/

static int n;
static int m;

int solve (const string &s1, const string &s2, int i, int j, vector <vector <int>> &t)
{
    if (i == 0 && j == 0)
    return true;
    
    if (t[i][j] != -1)
    return t[i][j];
    
    if (j == 0)
    return false;
    
    bool x = false;
    
    if (i == 0)
    {
        if (t[i][j - 2] != -1)
        x = t[i][j - 2];
        else
        x = solve(s1, s2, i, j - 2, t);
        
        return t[i][j] = (s2[j - 1] == '*' ? x : false);
    }
    
    bool back = false;
    
    if (s1[i - 1] == s2[j - 1])
    {
        if (t[i - 1][j - 1] != -1)
        return t[i][j] = t[i - 1][j - 1];
        else
        return t[i][j] = solve(s1, s2, i - 1, j - 1, t);
    }
    
    else if (s2[j - 1] == '.')
    {
        if (t[i - 1][j - 1] != -1)
        return t[i][j] = t[i - 1][j - 1];
        else
        return t[i][j] = solve(s1, s2, i - 1, j - 1, t);
    }
    
    else if (s2[j - 1] == '*')
    {
        bool a = false;
        bool b = false;
        
        if (s1[i - 1] == s2[j - 2] || s2[j - 2] == '.')
        {
            if (t[i - 1][j] != -1)
            a = t[i - 1][j];
            else
            a = solve(s1, s2, i - 1, j, t);
        }
        
        if (t[i][j - 2] != -1)
        b = t[i][j - 2];
        else
        b = solve(s1, s2, i, j - 2, t);
        
        return t[i][j] = a || b;
    }
    
    return t[i][j] = false;
}

int Solution::isMatch(const string A, const string B) {
    
    n = A.size();
    m = B.size();
    
    if (A == B)
    return 1;
    
    vector <vector <int>> t(n + 1, vector <int> (m + 1, -1));
    
    return solve (A, B, n, m, t);
    
}
