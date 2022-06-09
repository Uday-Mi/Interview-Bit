/*
Given a string A. The string contains alphanumeric characters.
Find the sum of all numbers present in it.

Note: All the numbers will fit in a 32-bit signed integer.


Problem Constraints
1 <= |A| <= 105


Input Format
The first and only argument is a string A.


Output Format
Return an integer.


Example Input
Input 1:
A = "a12b34c"
Input 2:

A = "123"


Example Output
Output 1:
Output 2:

123


Example Explanation
Explanation 1:
The numbers are 12, 34.
12 + 34 = 46
Explanation 2:

The only number is 123.
**/

long Solution::solve(string A) {

    long sum = 0;
    long a = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (isdigit(A[i]))
        {
            while (isdigit(A[i]) && i < A.size())
            {
                a = a * 10 + (A[i] - '0');
                i++;
            }
            sum = sum + a;
            a = 0;
        }
    }
    return sum;
}
