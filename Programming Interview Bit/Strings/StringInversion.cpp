/*
Given a string A. Change the cases of all the characters.
If the character is lowercase convert it to uppercase and if the character is uppercase convert it to lowercase.

Note: All the characters in the string are latin uppercase or lowercase letters.


Problem Constraints
1 <= |A| <= 105


Input Format
Given a string A.


Output Format
Return a string.


Example Input
Input 1:
A = 6 = "InterviewBit"
Input 2:

A = "Scaler"


Example Output
Output 1:
"iNTERVIEWbIT"
Output 2:

"sCALER"
**/

string Solution::solve(string A) {
    
    int n = A.size();
    
    for (int i = 0; i < n; i++)
    {
        char ch = A[i];
        
        if (ch >= 97 && ch <= 122)
        A[i] = toupper(ch);
        else
        A[i] = tolower(ch);
    }
    return A;
    
}
