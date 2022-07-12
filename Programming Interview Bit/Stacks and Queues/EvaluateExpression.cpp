/*
An arithmetic expression is given by a charater array A of size N. Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each character may be an integer or an operator.



Problem Constraints
1 <= N <= 105



Input Format
The only argument given is character array A.



Output Format
Return the value of arithmetic expression formed using reverse Polish Notation.



Example Input
Input 1:
    A =   ["2", "1", "+", "3", ""]
Input 2:
    A = ["4", "13", "5", "/", "+"]


Example Output
Output 1:
    9
Output 2:
    6


Example Explanation*
Explaination 1:
    starting from backside:
    * : () * ()
    3 : () * (3)
    + : (() + ()) * (3)
    1 : (() + (1)) * (3)
    2 : ((2) + (1)) * (3)
    ((2) + (1)) * (3) = 9
Explaination 2:
    + : () + ()
    / : () + (() / ())
    5 : () + (() / (5))
    13 : () + ((13) / (5))
    4 : (4) + ((13) / (5))
    (4) + ((13) / (5)) = 6
    **/

int Solution::evalRPN(vector<string> &A) {
    
    int n = A.size();
    
    stack <string> s;
    
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        string str = A[i];
        if (str == "+" || str == "-" || str == "*" || str == "/" || str == "")
        {
            string s1 = s.top();
            s.pop();
            string s2 = s.top();
            s.pop();
            
            // int a = s1 - "0";
            int a = stoi(s2);
            // int b = s2 - "0";
            int b = stoi(s1);
            
            if (str == "+")
            sum = sum + (a + b);
            if (str == "-")
            sum = sum + (a - b);
            if (str == "*" || str == "")
            sum = sum + (a * b);
            if (str == "/")
            sum = sum + (int)(a / b);
            
            s.push(to_string(sum));
            sum = 0;
        }
        else
        {
            s.push(str);
        }
    }
    
    int a = stoi(s.top());
    return a;
    
}
