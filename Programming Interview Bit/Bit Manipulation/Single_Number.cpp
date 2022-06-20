/*
Given an array of integers A, every element appears twice except for one. Find that single one.


NOTE: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?



Problem Constraints
2 <= |A| <= 2000000

0 <= A[i] <= INTMAX



Input Format
First and only argument of input contains an integer array A.



Output Format
Return a single integer denoting the single element.



Example Input
Input 1:

 A = [1, 2, 2, 3, 1]
Input 2:

 A = [1, 2, 2]


Example Output
Output 1:

 3
Output 2:

 1


Example Explanation
Explanation 1:

3 occurs once.
Explanation 2:

1 occurs once.
**/

int Solution::singleNumber(const vector<int> &A) {
    
    int n = A.size();
    
    vector <int> v;
    v = A;
    
    sort (v.begin(), v.end());
    
    for (int i = 0; i < n; i++)
    {
        if (v[i] == v[i + 1])
        {
            i++;
            continue;
        }
        return v[i];
    }
    return 0;
    
}
