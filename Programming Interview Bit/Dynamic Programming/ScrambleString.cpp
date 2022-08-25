/*
Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of A = “great”:


    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”.



Given two strings A and B of the same length, determine if B is a scrambled string of S.



Input Format:

The first argument of input contains a string A.
The second argument of input contains a string B.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= len(A), len(B) <= 50
Examples:

Input 1:
    A = "we"
    B = "we"

Output 1:
    1

Input 2:
    A = "phqtrnilf"
    B = "ilthnqrpf"
    
Output 2:
    0
**/

unordered_map <string, bool> mp;

int solve (string a, string b)
{
    if (a == b)
    return 1;
    
    if (a.size() <= 1)
    return 0;
    
    int n = a.size();
    int flag = 0;
    
    string key = a + " " + b;
    
    if (mp.find(key) != mp.end())
    return mp[key];
    
    for (int i = 1; i <= n - 1; i++)
    {
        if ((solve(a.substr(0, i), b.substr(0, i)) == true && solve(a.substr(i, n - i), b.substr(i, n - i)) == true) || (solve(a.substr(0, i), b.substr(n - i, i)) == true && solve(a.substr(i, n - i), b.substr(0, n - i)) == true))
        {
            flag = 1;
            break;
        }
    }
    return mp[key] = flag;
}

int Solution::isScramble(const string A, const string B) {
    
    int n = A.size();
    int m = B.size();
    
    if (n != m)
    return 0;
    
    return solve (A, B);
    
}
