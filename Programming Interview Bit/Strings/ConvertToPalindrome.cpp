/*
Given a string A consisting only of lowercase characters, we need to check whether it is possible to make this string a palindrome after removing exactly one character from this.

If it is possible then return 1 else return 0.



Problem Constraints
3 <= |A| <= 105

 A[i] is always a lowercase character.



Input Format
First and only argument is an string A.



Output Format
Return 1 if it is possible to convert A to palindrome by removing exactly one character else return 0.



Example Input
Input 1:

 A = "abcba"
Input 2:

 A = "abecbea"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 We can remove character ‘c’ to make string palindrome
Explanation 2:

 It is not possible to make this string palindrome just by removing one character 
 **/

int isPalindrome (string str)
{
    int i = 0;
    int j = str.size() - 1;
    
    while (i <= j)    
    {
        if (str[i] != str[j])
        return 0;
        
        i++;
        j--;
    }
    return 1;
}

int Solution::solve(string A) {
    
    int n = A.size();
    
    string str = A;
    
    int start = 0;
    int end = n - 1;
    
    while (start < end)
    {
        if (A[start] == A[end])
        {
            start++;
            end--;
        }
        else
        break;
    }
    
    if (start == end)
    return 1;
    
    else
    {
        return isPalindrome(A.erase(start, 1)) || isPalindrome(str.erase(end, 1));
    }
    
    return 0;
        
}
