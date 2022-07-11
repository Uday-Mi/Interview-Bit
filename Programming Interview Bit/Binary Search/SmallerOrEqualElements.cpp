/*
Given an sorted array A of size N. Find number of elements which are less than or equal to B.

NOTE: Expected Time Complexity O(log N)



Problem Constraints
1 <= N <= 106

1 <= A[i], B <= 109



Input Format
First agument is an integer array A of size N.

Second argument is an integer B.



Output Format
Return an integer denoting the number of elements which are less than or equal to B.



Example Input
Input 1:

 A = [1, 3, 4, 4, 6]
 B = 4
Input 2:

 A = [1, 2, 5, 5]
 B = 3


Example Output
Output 1:

 4
Output 2:

 2


Example Explanation
Explanation 1:

 Elements (1, 3, 4, 4) are less than or equal to 4.
Explanation 2:

 Elements (1, 2) are less than or equal to 3.
 **/

int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    int lo = 0;
    int hi = n - 1;
    int mid = (lo + hi) / 2;
    
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (A[mid] == B)
        {
            int i = mid + 1;
            for (; i < n; i++)
            {
                if (A[i] == B)
                mid++;
                else
                break;
            }
            return mid + 1;
        }
        
        if (A[mid] > B)
        hi = mid - 1;
        
        if (A[mid] < B)
        lo = mid + 1;
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        int a = A[i];
        int b = A[i + 1];
        
        if (B > a && B < b)
        return i + 1;
    }
    
    if (A[n - 1] < B)
    return n;
    
    if (A[0] > B)
    return 0;
    
    return 0;
    
}
