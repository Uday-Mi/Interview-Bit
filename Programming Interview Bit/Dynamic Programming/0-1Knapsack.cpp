/*
Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.

Also given an integer C which represents knapsack capacity.

Find out the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.

NOTE:

You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).


Problem Constraints
1 <= N <= 103

1 <= C <= 103

1 <= A[i], B[i] <= 103



Input Format
First argument is an integer array A of size N denoting the values on N items.

Second argument is an integer array B of size N denoting the weights on N items.

Third argument is an integer C denoting the knapsack capacity.



Output Format
Return a single integer denoting the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.



Example Input
Input 1:

 A = [60, 100, 120]
 B = [10, 20, 30]
 C = 50
Input 2:

 A = [10, 20, 30, 40]
 B = [12, 13, 15, 19]
 C = 10


Example Output
Output 1:

 220
Output 2:

 0


Example Explanation
Explanation 1:

 Taking items with weight 20 and 30 will give us the maximum value i.e 100 + 120 = 220
Explanation 2:

 Knapsack capacity is 10 but each item has weight greater than 10 so no items can be considered in the knapsack therefore answer is 0.
 **/

// METHOD 1 -- DYNAMIC PROGRAMMING

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    vector <int> val = A;
    vector <int> wt = B;
    int w = C;
    
    int n = val.size();
    
    int t[n + 1][w + 1];
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            t[i][j] = 0;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] <= j)
            t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            
            else
            t[i][j] = t[i - 1][j];
        }
    }
    
    return t[n][w];
    
}

// METHOD - 2 -- RECURSION WITH MEMOIZATION

int t[1001][1001];

int Knapsack(vector <int> &val, vector <int> &wt, int w, int n)
{
    if (n == 0 || w == 0)
    return 0;
    
    if (t[n][w] != -1)
    return t[n][w];
    
    if (wt[n - 1] <= w)
    return t[n][w] = max(val[n - 1] + Knapsack(val, wt, w - wt[n - 1], n - 1), Knapsack(val, wt, w, n - 1));
    
    else
    return t[n][w] = Knapsack(val, wt, w, n - 1);
}

int Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    memset(t, -1, sizeof(t));
    
    return Knapsack(A, B, C, A.size());
}
