/*
Given a string S, reverse the string using stack.

Example :

Input : "abc"
Return "cba"
PROBLEM APPROACH :

Complete solution in hints.
**/

string Solution::reverseString(string A) {
    
    int n = A.size();
    
    stack <char> s;
    
    for (int i = 0; i < n; i++)
    {
        char ch = A[i];
        s.push(ch);
    }
    
    string str = "";
    
    for (int i = 0; i < n; i++)
    {
        str = str + s.top();
        s.pop();
    }
    
    return str;
    
}
