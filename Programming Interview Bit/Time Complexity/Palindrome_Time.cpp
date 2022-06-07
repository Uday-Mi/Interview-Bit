/*
Given a string A which represents a time in 24 hour HH:MM format.
Find the minimum number of minutes need to pass to reach palindromic time.
Let some time be XY:ZW then it is palindromic if X == W and Y == Z.


Problem Constraints
String A represents a valid time in HH:MM format.


Input Format
Given a string A.


Output Format
Return an integer.


Example Input
Input 1:
A = "23:59"
Input 2:

A = "21:00"


Example Output
Output 1:
1
Output 2:

12


Example Explanation
Explanation 1:
After 1 minute time will be 00:00 which is a palindromic time.
Explanation 2:

After 12 minute time will be 21:12 which is a palindromic time.
**/

int Solution::solve(string A) {

    int hr, min;
    int i = 0;

    hr = (A[0] - '0') * 10 + (A[1] - '0');
    min = (A[3] - '0') * 10 + (A[4] - '0');

    while (true)
    {
        if ((hr / 10 == min % 10) && (hr % 10 == min / 10))
        {
            break;
        }
        else
        {
            min++;
            if (min >= 60)
            {
                min = 0;
                hr++;
                if (hr >= 24)
                {
                    hr = 0;
                }
            }
            i++;
            continue;
        }
    }
    return i;

}
