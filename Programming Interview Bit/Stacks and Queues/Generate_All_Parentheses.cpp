/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

PROBLEM APPROACH :

Complete solution in hints.
**/

int open (char a);
int close (char a);
char complement (char a);

int Solution::isValid(string A) {
    
    int n = A.size();
    
    stack <char> s;
    
    for (int i = 0; i < n; i++)
    {
        char ch = A[i];
        
        if (open(ch))
        s.push(ch);
        
        if (close(ch))
        {
            if (s.empty())
            return 0;
            
            char a = s.top();
            char b = complement(a);
            
            if (ch != b)
            return 0;
            
            s.pop();
        }
    }
    if (s.empty() == true)
    return 1;
    
    return 0;
}

int open (char a)
{
    if (a == '(' || a == '{' || a == '[')
    return 1;
    return 0;
}

int close (char a)
{
    if (a == ')' || a == '}' || a == ']')
    return 1;
    return 0;
}

char complement (char a)
{
    if (a == '(')
    return ')';
    
    if (a == '{')
    return '}';
    
    if (a == '[')
    return ']';
}
