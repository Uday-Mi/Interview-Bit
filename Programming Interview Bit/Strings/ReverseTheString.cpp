/*
Given a string A.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.

Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

If there are multiple spaces between words, reduce them to a single space in the reversed string.


 Input Format

The only argument given is string A.
Output Format

Return the string A after reversing the string word by word.
For Example

Input 1:
    A = "the sky is blue"
Output 1:
    "blue is sky the"

Input 2:
    A = "this is ib"
Output 2:
    "ib is this"

Input 3:
 A = " hello world "
Output 3:
 "world hello"
 **/

  string Solution::solve(string A) {
    
    A = A + " ";
    
    int n = A.size();
    
    string str = "";
    string s = "";
    
    for (int i = 0; i < n; i++)
    {
        char ch = A[i];
        
        if (ch == ' ' && s != "")
        {
            if (str != "")
            str = s + " " + str;
            if (str == "")
            str = s + str;
            s = "";
        }
        
        if (ch != ' ')
        s = s + ch;
    }
    
    return str;
    
}
