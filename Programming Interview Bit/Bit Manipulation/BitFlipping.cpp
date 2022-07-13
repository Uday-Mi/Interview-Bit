/*
Given an integer A.
Write binary representation of the integer without leading zeros.
Flip all bits then return the integer value of the binary number formed.
Flipping means 0 -> 1 and 1 -> 0.


Problem Constraints
1 <= A <= 109


Input Format
Given an integer A.


Output Format
Return an integer.


Example Input
Input 1:
A = 7
Input 2:

A = 5


Example Output
Output 1:
0
Output 2:

2


Example Explanation
Explanation 1:
7 -> 111 -> 000 ->0
Explanation 2:

5 -> 101 -> 010 ->3
**/

int Solution::solve(int A) {
    
    vector <int> v;
    
    int a = A;
    
    int sum = 0;
    
    while (A != 0)
    {
        int x = A % 2;
        
        if (x == 0)
        x = 1;
        else
        x = 0;
        
        v.push_back(x);
        A = A / 2;
    }
    
    int n = v.size();
    
    for (int i = 0; i < n; i++)
    {
        sum = sum + v[i] * pow(2, i);
    }
    
    return sum;
    
}
