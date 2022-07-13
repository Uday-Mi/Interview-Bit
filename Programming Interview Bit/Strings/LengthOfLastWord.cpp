/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",


return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.
**/

int Solution::lengthOfLastWord(const string A) {
    
    int n = A.size();
    
    if (n == 0)
    return 0;
    
    if (n == 1)
    {
        if (A[0] != ' ')
        return 1;
        else
        return 0;
    }
    
    string str = A;
    str = str + " ";
    
    n = str.size();
    
    string s = "";
    int a = 0;
    
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        if (ch == ' ' && str[i - 1] != ' ')
        {
            a = s.size();
            s = "";
        }
        if (ch != ' ')
        s = s + ch;
    }
    
    return a;
    
}
