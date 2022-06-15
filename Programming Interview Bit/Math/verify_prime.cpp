/*
Given a number N, verify if N is prime or not.

Return 1 if N is prime, else return 0.

Example :

Input : 7
Output : True
Problem Approach:

VIDEO : https://www.youtube.com/watch?v=7VPA-HjjUmU

Complete code in the hint.
**/

int Solution::isPrime(int A) {
    if (A == 1)
    return 0;
    int s = (int)sqrt(A);
    for (int i = 2; i <= s; i++)
    {
        if (A % i == 0)
        return 0;
    }
    return 1;
}
