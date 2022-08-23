/*
You are given an integer N and the task is to reverse the digits of the given integer. Return 0 if the result overflows and does not fit in a 32 bit signed integer


Look at the example for clarification.



Problem Constraints
N belongs to the Integer limits.



Input Format
Input an Integer.



Output Format
Return a single integer denoting the reverse of the given integer.



Example Input
Input 1:

 x = 123


Input 2:

 x = -123


Example Output
Output 1:

 321


Ouput 2:

 -321


Example Explanation
 If the given integer is negative like -123 the output is also negative -321.
 **/

int Solution::reverse(int A) {
    
    int sign = 1;
    
    if (A < 0)
    {
        sign = -1;
    }
    
    A = A * sign;
    
    long long int a = 0;
    
    while (A != 0)
    {
        int r = A % 10;
        a = a * 10 + r;
        A = A / 10;
    }
    
    a = a * sign;
    
    if (a > INT_MAX || a < INT_MIN)
    return 0;
    
    return a;
    
}
