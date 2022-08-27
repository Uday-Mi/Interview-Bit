/*
Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most 2 transactions.

Return the maximum possible profit.

Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).



Input Format:

The first and the only argument is an integer array, A.
Output Format:

Return an integer, representing the maximum possible profit.
Constraints:

1 <= length(A) <= 7e5
1 <= A[i] <= 1e7
Examples:

Input 1:
    A = [1, 2, 1, 2]

Output 1:
    2

Explanation 1: 
    Day 0 : Buy 
    Day 1 : Sell
    Day 2 : Buy
    Day 3 : Sell

Input 2:
    A = [7, 2, 4, 8, 7]

Output 2:
    6

Explanation 2:
    Day 1 : Buy
    Day 3 : Sell
**/

static int n;

int t[700001][4];

int solve (const vector <int> &arr, int i, int c)
{
    if (i >= n)
    return 0;
    
    if (c >= 4)
    return 0;
    
    if (t[i][c] != -1)
    return t[i][c];
    
    int buy = 0;
    int sell = 0;
    
    if (c == 0 || c == 2)
    buy = max(solve(arr, i + 1, c + 1) - arr[i], solve(arr, i + 1, c));
    
    if (c == 1 || c == 3)
    sell = max(solve(arr, i + 1, c + 1) + arr[i], solve(arr, i + 1, c));
    
    return t[i][c] = buy + sell;
    
}

int Solution::maxProfit(const vector<int> &A) {
    
    n = A.size();
    
    if (n == 0 || n == 1)
    return 0;
    
    memset(t, -1, sizeof(t));
    
    return solve(A, 0, 0);
    
}
