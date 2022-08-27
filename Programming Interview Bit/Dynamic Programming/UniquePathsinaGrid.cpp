/*
Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
**/

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    
    int n = A.size();
    int m = A[0].size();
    
    int t[n + 1][m + 1];
    
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = 0;
    }
    
    for (int i = 0; i <= m; i++)
    {
        t[0][i] = 0;
    }
    
    t[1][1] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i - 1][j - 1] == 0)
            {
                if (i == 1 && j == 1)
                continue;
                t[i][j] = t[i - 1][j] + t[i][j - 1];
            }
            else
            t[i][j] = 0;
        }
    }
    
    return t[n][m];
    
}
