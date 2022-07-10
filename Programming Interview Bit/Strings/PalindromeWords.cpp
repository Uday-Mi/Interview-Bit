/*
Given a sentence as a string A.
Return the number of palindromic words in the sentence.


Problem Constraints
1 <= A <= 105
Ai = {Lowercase English letters and whitespaces}


Input Format
The first and only argument is a string A.


Output Format
Return an integer.


Example Input
Input 1:
A = "the fastest racecar"
Input 2:

A = "wow mom"


Example Output
Output 1:
1
Output 2:

2


Example Explanation
Explanation 1:
The words are "hello" and "world".
12 + 34 = 46
Explanation 2:

The words are "how", "are" and "you".
**/

int Solution::solve(string A) {
    
    A = A + " ";
    int n = A.size();
    
    string str = "";
    string s = "";
    int c = 0;
    
    for (int i = 0; i < n; i++)
    {
        char ch = A[i];
        
        if (ch == ' ')
        {
            if (str == s)
            {
                c++;
            }
            str = "";
            s = "";
        }
        else
        {
            str = str + ch;
            s = ch + s;
        }
    }
    return c;
    
}
