/*
A robot is located at the top-left corner of an A x B grid (marked ‘Start’ in the diagram below).

Path Sum: Example 1

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).

How many possible unique paths are there?

Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.

Example :

Input : A = 2, B = 2
Output : 2

2 possible routes : (0, 0) -> (0, 1) -> (1, 1) 
              OR  : (0, 0) -> (1, 0) -> (1, 1)
              
**/

//ITERATIVE APPROACH

int Solution::uniquePaths(int A, int B) {
    
    if (A < B)
    return uniquePaths(B, A);
    
    vector <int> v;
    
    for (int i = 0; i < A; i++)
    {
        v.push_back(1);
    }
    
    for (int i = 1; i < B; i++)
    {
        for (int j = 1; j < A; j++)
        {
            v[j] = v[j] + v[j - 1];
        }
    }
    
    return v[A - 1];
    
}

// RECURSIVE APPROACH

int Solution::uniquePaths(int A, int B) {
    
    if (A == 1 || B == 1)
    return 1;
    
    return uniquePaths(A - 1, B) + uniquePaths(A, B - 1); 
  
}

