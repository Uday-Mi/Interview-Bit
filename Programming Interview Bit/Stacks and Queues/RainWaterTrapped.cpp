/*
Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.



Problem Constraints
1 <= |A| <= 100000



Input Format
The only argument given is integer array A.



Output Format
Return the total water it is able to trap after raining.



Example Input
Input 1:

 A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Input 2:

 A = [1, 2]


Example Output
Output 1:

 6
Output 2:

 0


Example Explanation
Explanation 1:

 
 In this case, 6 units of rain water (blue section) are being trapped.
Explanation 2:

 No water is trapped.
 **/

int Solution::trap(const vector<int> &A) {
    
    int n = A.size();
    
    vector <int> mxl(n);
    vector <int> mxr(n);
    
    mxl[0] = A[0];
    mxr[n - 1] = A[n - 1];
    
    for (int i = 1; i < n; i++)
    {
        mxl[i] = max(A[i], mxl[i - 1]);
    }
    
    for (int i = n - 2; i >= 0; i--)
    {
        mxr[i] = max(mxr[i + 1], A[i]);
    }
    
    vector <int> water(n);
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        water[i] = min(mxr[i], mxl[i]) - A[i];
        sum = sum + water[i];
    }
    
    return sum;
    
}
