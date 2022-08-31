/*
Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers along its path.

NOTE: You can only move either down or right at any point in time. 



Input Format
First and only argument is an 2D integer array A of size M x N.



Output Format
Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).



Example Input
Input 1:

 A = [  [1, 3, 2]
        [4, 3, 1]
        [5, 6, 1]
     ]


Example Output
Output 1:

 8


Example Explanation
Explanation 1:

 The path is 1 -> 3 -> 2 -> 1 -> 1
 So ( 1 + 3 + 2 + 1 + 1) = 8
 **/

static int n;
static int m;

int solve (vector <vector <int>> &arr, int i, int j, vector <vector <int>> &t)
{    
    if (i == m - 1 && j == n - 1)
    return t[i][j] = arr[i][j];
    
    if (t[i][j] != -1)
    return t[i][j];
    
    if (i == m - 1)
    return t[i][j] = arr[i][j] + solve(arr, i, j + 1, t);
    
    if (j == n - 1)
    return t[i][j] = arr[i][j] + solve(arr, i + 1, j, t);
    
    return t[i][j] = min(arr[i][j] + solve(arr, i + 1, j, t), arr[i][j] + solve(arr, i, j + 1, t));
}

int Solution::minPathSum(vector<vector<int> > &A) {
    
    m = A.size();
    n = A[0].size();
    
    vector <vector <int>> t(m + 1, vector <int> (n + 1, -1));
    
    return solve (A, 0, 0, t);
    
}
