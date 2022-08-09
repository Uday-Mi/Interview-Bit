/*
Say you have an array, A, for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Return the maximum possible profit.



Problem Constraints
0 <= len(A) <= 7e5

1 <= A[i] <= 1e7



Input Format
The first and the only argument is an array of integers, A.



Output Format
Return an integer, representing the maximum possible profit.



Example Input
Input 1:

 A = [1, 2]
Input 2:

 A = [1, 4, 5, 2, 4]


Example Output
Output 1:
 1
Output 2:

 4


Example Explanation
Explanation 1:

 Buy the stock on day 0, and sell it on day 1.
Explanation 2:

 Buy the stock on day 0, and sell it on day 2.
 **/

int Solution::maxProfit(const vector<int> &A) {
  
    int n = A.size();
    
    if (n == 0)
    return 0;
    
    int mx = 0;
    int mn = A[0];
    
    for (int i = 0; i < n; i++)
    {
        mx = max(A[i] - mn, mx);
        mn = min(A[i], mn);
    }
  
    return mx;
    
}
