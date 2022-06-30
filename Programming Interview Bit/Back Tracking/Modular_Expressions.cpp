/*
Implement pow(A, B) % C.

In other words, given A, B and C, 

find (AB)%C.

Input : A = 2, B = 3, C = 3
Return : 2 
2^3 % 3 = 8 % 3 = 2
PROBLEM APPROACH :

Complete solution in the hint.
**/

long long power (long long a, long long b, long long c);

int Solution::Mod(int A, int B, int C) {
    
    if (A == 0)
    return 0;
    
    if (A < 0)
    A = (A % C + C) % C;
    
    return power(A, B, C);
    
}

long long power (long long a, long long b, long long c)
{
    if (b == 0)
    return 1;
    
    if (b == 1)
    return a % c;
    
    long long res = power(a, b / 2, c) % c;
    
    if (b % 2 == 0)
    return (res * res) % c;
    
    return ((res * res) % c * (a % c)) % c;
}
