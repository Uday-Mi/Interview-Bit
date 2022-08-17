/*
Given the start day of the month A and number of days in the month B, find number of sundays in the month.


Problem Constraints
A = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}
1 <= B <= 109


Input Format
First argument is an string A.
Second argument is an integer B.


Output Format
Return an integer.


Example Input
Input 1:
A = "Sunday"
B = 1
Input 2:

A = "Monday"
B = 14


Example Output
Output 1:
1
Output 2:

2


Example Explanation
Explanation 1:
The only day in the month is sunday.
Explanation 2:

The 7th and 14th day of the month will be sunday
**/

int Solution::solve(string A, int B) {
    
    int n = 0;
    
    if (A == "Monday")
    return B / 7;
    if (A == "Tuesday")
    n = 2;
    if (A == "Wednesday")
    n = 3;
    if (A == "Thursday")
    n = 4;
    if (A == "Friday")
    n = 5;
    if (A == "Saturday")
    n = 6;
    if (A == "Sunday")
    n = 7;
    
    int count = 0;
    
    count = count + (B + n - 1) / 7;
    
    return count;
    
}
