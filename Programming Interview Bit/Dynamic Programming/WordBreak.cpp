/*
Given a string A and a dictionary of words B, determine if A can be segmented into a space-separated sequence of one or more dictionary words.

Input Format:

The first argument is a string, A.
The second argument is an array of strings, B.
Output Format:

Return 0 / 1 ( 0 for false, 1 for true ) for this problem.
Constraints:

1 <= len(A) <= 6500
1 <= len(B) <= 10000
1 <= len(B[i]) <= 20
Examples:

Input 1:
    A = "myinterviewtrainer",
    B = ["trainer", "my", "interview"]

Output 1:
    1

Explanation 1:
    Return 1 ( corresponding to true ) because "myinterviewtrainer" can be segmented as "my interview trainer".
    
Input 2:
    A = "a"
    B = ["aaa"]

Output 2:
    0

Explanation 2:
    Return 0 ( corresponding to false ) because "a" cannot be segmented as "aaa".
**/

static int n;

unordered_map <string, bool> t;

unordered_map <string, bool> str;

int solve (string s, vector <string> &v)
{
    if (s == "")
    return true;
    
    if (t.find(s) != t.end())
    return t[s];
    
    bool ans = false;
    
    for (int i = 0; i < n; i++)
    {
        string word = s.substr(0, i + 1);
        int m = word.length();
        
        if (str.find(word) != str.end())
        {
            string rem = s.substr(m, n - m);
            ans = solve(rem, v);
            
            if (ans == true)
            return t[s] = true;
        }
    }
    
    return t[s] = ans;
}

int Solution::wordBreak(string A, vector<string> &B) {
    
    n = A.length();
    
    str.clear();
    t.clear();
    
    for (int i = 0; i< B.size(); i++)
    {
        str[B[i]] = true;
    }
    
    return (solve(A, B) == true);
    
}
