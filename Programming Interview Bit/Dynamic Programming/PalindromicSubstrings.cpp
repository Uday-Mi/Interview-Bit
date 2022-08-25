/*
Given a string A consisting of only lowercase English letters.
Return the number of substrings of A which are palindrome.


Problem Constraints
1 <= A <= 103


Input Format
The first and only argument is a string A.


Output Format
Return an integer.


Example Input
Input 1:
A = "aba"
Input 2:

A = "abcd"


Example Output
Output 1:
4
Output 2:

4


Example Explanation
Explanation 1:
The plaindrome substrings are "a", "b", "a" and "aba".
Explanation 2:

The plaindrome substrings are "a", "b", "c" and "d".
**/

int palindrome (string str, int i, int j)
{
    int ans = 0;
    
    while (i > -1 && j < str.size())
    {
        if (str[i] == str[j])
        {
            ans++;
            i--;
            j++;
        }
        else
        break;
    }
    
    return ans;
}

int Solution::solve(string A) {
    
    int n = A.size();
    
    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        ans = ans + palindrome(A, i, i);
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        ans = ans + palindrome(A, i, i + 1);
    }
    
    return ans;
    
}
