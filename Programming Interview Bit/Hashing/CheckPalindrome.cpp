/*
Given a string A consisting of lowercase characters.

Check if characters of the given string can be rearranged to form a palindrome.

Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.



Problem Constraints
1 <= |A| <= 105

A consists only of lower-case characters.



Input Format
First argument is an string A.



Output Format
Return 1 if it is possible to rearrange the characters of the string A such that it becomes a palindrome else return 0.



Example Input
Input 1:

 A = "abcde"
Input 2:

 A = "abbaee"


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 No possible rearrangement to make the string palindrome.
Explanation 2:

 Given string "abbaee" can be rearranged to "aebbea" to form a palindrome.
 
 **/

int Solution::solve(string A) {
    
    int n = A.size();
    
    unordered_map <char, int> mp;
    
    for (int i = 0; i < n; i++)
    {
        mp[A[i]]++;
    }
    
    int m = mp.size();
    int c1 = 0;
    int c2 = 0;
    
    for (auto x : mp)
    {
        if (x.second % 2 == 1)
        c1++;
    }
    
    if (c1 == 0 || c1 == 1)
    return 1;
    else
    return 0;
}
