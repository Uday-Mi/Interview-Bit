/*
Print concentric rectangular pattern in a 2d matrix. 

Let us show you some examples to clarify what we mean.

Example 1:

Input: A = 4.

Output:

4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
Example 2:

Input: A = 3.

Output:

3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3 
The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.

You will be given A as an argument to the function you need to implement, and you need to return a 2D array.
**/

vector<vector<int> > Solution::prettyPrint(int A) {
    
    int n = 2 * A - 1;
    
    vector <vector <int>> a(n, vector <int> (n, 0));
    
    int row_first = 0;
    int row_last = n - 1;
    int col_first = 0;
    int col_last = n - 1;
    int count = 0;
    
    while (A >= 1)
    {
        for (int i = 0 + count; i < n - count; i++)
        {
            a[row_first][i] = A;
            a[row_last][i] = A;
            a[i][col_first] = A;
            a[i][col_last] = A;
        }
        
        row_first++;
        row_last--;
        col_first++;
        col_last--;
        A--;
        count++;
    }
    
    return a;
    
}
