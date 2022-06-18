/*
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed. Negative numbers are not palindromic.

Example :

Input : 12121
Output : 1


Input : 123
Output : 0
**/

int Solution::isPalindrome(int A) {
    
    if (A < 0)
    return 0;
    
    int n = A;
    int m = 0;
    
    while (n != 0)
    {
        m = m * 10 + (n % 10);
        n = n / 10;
    }
    
    return (m == A);
}
