/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Return an integer corresponding to the maximum product possible.

Example :

Input : [2, 3, -2, 4]
Return : 6 

Possible with [2, 3]
**/

int Solution::maxProduct(const vector<int> &A) {
    
    int n = A.size();
    int ans = INT_MIN;
    int prod = 1;
    
    for (int i = 0; i < n; i++)
    {
        prod = prod * A[i];
        ans = max(ans, prod);
        
        if (prod == 0)
        prod = 1;
    }
    
    prod = 1;
    
    for (int i = n - 1; i >= 0; i--)
    {
        prod = prod * A[i];
        ans = max(ans, prod);
        
        if (prod == 0)
        prod = 1;
    }
    
    return ans;
    
}
