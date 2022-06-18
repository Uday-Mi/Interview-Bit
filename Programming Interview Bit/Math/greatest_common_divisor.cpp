/*
Given 2 non negative integers m and n, find gcd(m, n)

GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.

Both m and n fit in a 32 bit signed integer.

Example

m : 6
n : 9

GCD(m, n) : 3 
NOTE : DO NOT USE LIBRARY FUNCTIONS
**/

int Solution::gcd(int A, int B) {
    
    int c = 1;
    int m = min(A, B);
    
    if (A == 0)
    return B;
    
    if (B == 0)
    return A;
    
    if (A % m == 0 && B % m == 0)
    return m;
    
    for (int i = 2; i < m; i++)
    {
        if (A % i == 0 && B % i == 0)
        c = i;
    }
    
    return c;
    
}
