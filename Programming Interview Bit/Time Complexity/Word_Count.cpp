/*
Given a string A. The string contains some words separated by spaces.
Return the number of words in the given string.


Problem Constraints
1 <= |A| <= 105
Ai = { lowercase English letters or spaces}


Input Format
The first and only argument is a string A.


Output Format
Return an integer.


Example Input
Input 1:
A = "bonjour"
Input 2:

A = "hasta la vista"


Example Output
Output 1:
1
Output 2:

3


Example Explanation
Explanation 1:
The string has only one word "bonjour".
Explanation 2:

The string have three words "hasta", "la", "vista".
**/

int Solution::solve(string A) {
    
    int j = 0;
    string str = "";
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == ' ' && A[i - 1] != ' ')
        j++;
    }
    if (A[A.size() - 1] != ' ')
    j++;
    
    return (j);
    
}

