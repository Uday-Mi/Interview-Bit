/*
Given an integer array A and two integers B and C.

You need to find the number of subarrays in which the number of occurrences of B is equal to number of occurrences of C.

NOTE: Don't count empty subarrays.



Problem Constraints
1 <= |A| <= 104

1 <= A[i], B, C <= 108

 B != C



Input Format
First argument is an integer array A.

Second argument is an integer B.

Third argument is an integer C.



Output Format
Return an integer denoting the number of subarrays in which the number of occurrences of B is equal to number of occurrences of C.



Example Input
Input 1:

 A = [1, 2, 1]
 B = 1
 C = 2
Input 2:

 A = {1, 2, 1}
 B = 4
 C = 6


Example Output
Output 1:

 2
Output 2:

 6


Example Explanation
Explanation 1:

 The possible sub-arrays have same equal number of occurrences of B and C are:
    1) {1, 2}, B and C have same occurrence(1).
    2) {2, 1}, B and C have same occurrence(1).
Explanation 2:

 The possible sub-arrays have same equal number of occurrences of B and C are:
    1) {1}, B and C have same occurrence(0).
    2) {2}, B and C have same occurrence(0).
    3) {1}, B and C have same occurrence(0).
    4) {1, 2}, B and C have same occurrence(0).
    5) {2, 1}, B and C have same occurrence(0).
    6) {1, 2, 1}, B and C have same occurrence(0).
**/

int Solution::solve(vector<int> &A, int B, int C) {
    
    int n = A.size();
    
    vector <int> v(2, 0);
    
    int count = 0;
    
    for (int i = 0; i < n; i++)
    {
        v[0] = 0;
        v[1] = 0;
        
        for (int j = i; j < n; j++)
        {
            if (A[j] == B)
            v[0]++;
            
            if (A[j] == C)
            v[1]++;
            
            if (v[1] == v[0])
            count++;
        }
    }
    
    return count;
    
}
