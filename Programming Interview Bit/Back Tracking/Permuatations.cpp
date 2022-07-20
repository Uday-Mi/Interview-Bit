/*
Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
NOTE

No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.
Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.

Example : next_permutations in C++ / itertools.permutations in python.

If you do, we will disqualify your submission retroactively and give you penalty points.
**/

vector <int> next_perm (vector <int> &A);

vector<vector<int> > Solution::permute(vector<int> &A) {
    
    int n = A.size();
    
    long long int f = 1;
    
    if (n == 0)
    f = 0;
    
    for (int i = 1; i <= n; i++)
    {
        f = f * i;
    }
    
    vector <vector <int>> G; 
    
    for (long long int i = 0; i < f; i++)
    {
        G.push_back(next_perm(A));
    }
    
    return G;
    
}

vector <int> next_perm (vector <int> &A)
{
    int n = A.size();
    
    int i = 0;
    int j = 0;
    
    for (i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        break;
    }
    
    if (i < 0)
    reverse(A.begin(), A.end());
    else
    {
        for (j = n - 1; j > i; j--)
        {
            if (A[j] > A[i])
            break;
        }
        swap(A[i], A[j]);
        reverse(A.begin() + i + 1, A.end());
    }
    
    return A;
}
