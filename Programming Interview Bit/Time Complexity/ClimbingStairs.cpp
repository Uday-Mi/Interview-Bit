/*
Given an integer array A of length N. Where Ai is the cost of stepping on the ith stair.
From ith stair, you can go to i+1th or i+2th numbered stair.
Initially, you are at 1st stair find the minimum cost to reach Nth stair.


Problem Constraints
2 <= N <= 105
1 <= Ai <= 104


Input Format
The first and only argument is an integer array A.


Output Format
Return an integer.


Example Input
Input 1:
A = [1, 2, 1, 3]
Input 2:

A = [1, 2, 3, 4]


Example Output
Output 1:
5
Output 2:

7


Example Explanation
Explanation 1:
1 -> 3 -> 4
Explanation 2:

1 -> 2 -> 4
**/

int t[100001];

int climb(vector <int> &arr, int n)
{
    if (n == 0)
    return 0;
    if (n == 1)
    return arr[n];
    if (n == 2)
    return arr[n];
    
    if (t[n] != -1)
    return t[n];
    
    return t[n] = min(climb(arr, n - 1) + arr[n], climb(arr, n - 2) + arr[n]);
}

int Solution::solve(vector<int> &A) {
    
    memset (t, -1, sizeof(t));
    
    int n = A.size();
    
    return climb(A, n - 1) + A[0];
    
}
