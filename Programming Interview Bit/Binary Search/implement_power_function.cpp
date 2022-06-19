/*
Implement pow(x, n) % d.
In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative. In other words, make sure the answer you return is non negative.



Problem Constraints
-109 <= x <= 109
0 <= n <= 109
1 <= d <= 109


Example Input
x = 2
n = 3
d = 3


Example Output
2


Example Explanation
23 % 3 = 8 % 3 = 2.
**/

int Solution::pow(int x, int n, int d) {
    
    long long int t = 1;
    
    long long int a = x;
    
    long long int b = n;
    
    a = a % d;
    
    while (b != 0)
    {
        if (b & 1)
        t = (t * a) % d;
        b = b >> 1;
        a = (a * a) % d;
    }
    
    long long int m = (t + d) % d;
    
    return m;
}
