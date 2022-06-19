/*
Given a string, determine if it is a palindrome. While checking for a palindrome, you have to ignore spaces, case, and all special characters; i.e. consider only alphanumeric characters.

Check the sample test case for reference.

Example:

Input 1:

"A man, a plan, a canal: Panama"

Input 2:

"race a car"

Output and Explanation 1:

1

The input string after ignoring spaces, and all special characters is "AmanaplanacanalPanama" which is a palindrome after ignoring the case.

Output and Explanation 2:

0

The input string after ignoring spaces, and all special characters is "raceacar" which is not a palindrome

 

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
**/

int Solution::isPalindrome(string A) {
    
    int n = A.size();
    
    if (n == 0)
    return 1;
    
    transform(A.begin(), A.end(), A.begin(), :: tolower);
    
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        char a = A[i];
        char b = A[j];
        if (!isalnum(a))
        {
            i++;
            continue;
        }
        if (!isalnum(b))
        {
            j--;
            continue;
        }
        if (isalnum(a) && isalnum(b))
        {
            if (a != b)
            return 0;
        }
        i++;
        j--;
        
    }
    
    return 1;
    
}
