/*
Given a password as a character array A.
Check if it is valid or not.
Password should have at least one numerical digit(0-9).
Password's length should be in between 8 to 15 characters.
Password should have at least one lowercase letter(a-z).
Password should have at least one uppercase letter(A-Z).
Password should have at least one special character ( @, #, %, &, !, $, *).


Problem Constraints
1 <= |A| <= 20


Input Format
Given a character array A.


Output Format
Return an integer.


Example Input
Input 1:
A = ['S', 'c', 'a', 'l', 'e', 'r', '@', '1']
Input 2:

A = ['I', 'n', 't', 'e', 'r', 'v', 'i', 'e', 'w', 'B', 'i', 't']


Example Output
Output 1:
1
Output 2:

0


Example Explanation
Explanation 1:
All the characteristic required for password are present in given password.
Explanation 2:

The password given does not have any special character and also it does not have any numerical digit.
**/

int Solution::solve(string A) {
    
    int n = A.size();
    
    if (n < 8 || n > 15)
    return 0;
    
    int f = 0;
    
    for (int i = 0; i < n; i++)
    {
        char ch = A[i];
        if (ch == '@' || ch == '#' || ch == '%' || ch == '&' || ch == '!' || ch == '$' || ch == '*')
        {
            f = 1;
            break;
        }
    }
    if (f == 0)
    return 0;
    
    f = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (isdigit(A[i]))
        {
            f = 1;
            break;
        }
    }
    
    if (f == 0)
    return 0;
    
    f = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (islower(A[i]))
        {
            f = 1;
            break;
        }
    }
    
    if (f == 0)
    return 0;
    
    f = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (isupper(A[i]))
        {
            f = 1;
            break;
        }
    }
    
    if (f == 0)
    return 0;
    
    return 1;
    
}
