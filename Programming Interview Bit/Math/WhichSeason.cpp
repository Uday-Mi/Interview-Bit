/*
Given an integer A which represents a month.
Find the season according to the month.
Spring – March to May
Summer – June to August
Autumn – September to November
Winter – December to February
If the month is out of the range 1 to 12 output should be “Invalid”.


Problem Constraints
1 <= A <= 100


Input Format
Given an integer A.


Output Format
Return a string.


Example Input
Input 1:
A = 6
Input 2:

A = 13


Example Output
Output 1:
"Summer"
Output 2:

"Invalid"


Example Explanation
Explanation 1:
6th month is june, in june there is "Summer".
Explanation 2:

13th month doesn't exist so "Invalid".
**/

string Solution::solve(int A) {
    
    if (A < 1 || A > 12)
    return "Invalid";
    
    if (A >= 3 && A <= 5)
    return "Spring";
    
    if (A >= 6 && A <= 8)
    return "Summer";
    
    if (A >= 9 && A <= 11)
    return "Autumn";
    
    if (A == 12 || (A >= 1 && A <= 2))
    return "Winter";
    
}
