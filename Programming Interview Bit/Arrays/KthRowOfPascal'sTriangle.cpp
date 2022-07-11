 /*
 Given an index k, return the kth row of the Pascal's triangle.
Pascal's triangle: To generate A[C] in row R, sum up A'[C] and A'[C-1] from previous row R - 1.

Example:

Input : k = 3


Return : [1,3,3,1]

Note: k is 0 based. k = 0, corresponds to the row [1]. 

Note: Could you optimize your algorithm to use only O(k) extra space?
**/

vector<int> Solution::getRow(int A) {   
    
    vector <int> v;
    vector <int> w;
    
    v.assign(A + 1, 0);
    w.assign(A + 1, 0);
    
    v[0] = 1;
    w[0] = 1;
    
    for (int i = 1; i <= A; i++)
    {
        for (int j = 1; j < i; j++)
        {
            w[j] = v[j] + v[j - 1];
        }
        w[i] = 1;
        v = w;
    }
    
    return w;
    
}
