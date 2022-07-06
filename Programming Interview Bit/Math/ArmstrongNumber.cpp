/*
Given an integer A, check if it is an Armstrong number of not.
An Armstrong number is a number that is the sum of its own digits each raised to the power of the number of digits.


Problem Constraints
1 <= A <= 109


Input Format
Given an integer A.


Output Format
Return an integer.


Example Input
Input 1:
A = 371
Input 2:

A = 123


Example Output
Output 1:
1
Output 2:

0


Example Explanation
Explanation 1:
3×3×3 + 7×7×7 + 1×1×1 = 371
Explanation 2:

1×1×1 + 2×2×2 + 3×3×3 != 123
**/

int Solution::solve(int A) {
    
    string str = to_string(A);
    int n = str.size();
    int a = A;
    long long int sum = 0;
    
    while (A != 0)
    {
        int r = A % 10;
        sum = sum + pow(r, n);
        A = A / 10;
    }
    
    if (sum == a)
    return 1;
    
    return 0;
    
}
