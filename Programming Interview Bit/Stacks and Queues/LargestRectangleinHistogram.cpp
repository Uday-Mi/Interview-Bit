/*
Given an array of integers A .

A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.

Find the area of the largest rectangle formed by the histogram.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 1000000000



Input Format
The only argument given is the integer array A.



Output Format
Return the area of largest rectangle in the histogram.



Example Input
Input 1:

 A = [2, 1, 5, 6, 2, 3]
Input 2:

 A = [2]


Example Output
Output 1:

 10
Output 2:

 2


Example Explanation
Explanation 1:

The largest rectangle has area = 10 unit. Formed by A[3] to A[4].
Explanation 2:

Largest rectangle has area 2.
**/

int Solution::largestRectangleArea(vector<int> &A) {
    
    int n = A.size();
    
    if (n == 1)
    return A[0];
    
    if (n == 0)
    return 0;
    
    vector <int> left;
    vector <int> right;
    
    stack <pair <int, int>> sleft;
    stack <pair <int, int>> sright;
    
    for (int i = 0; i < n; i++)
    {
        if (sleft.size() == 0)
        left.push_back(-1);
        
        else if (sleft.size() > 0 && sleft.top().first < A[i])
        left.push_back(sleft.top().second);
        
        else if (sleft.size() > 0 && sleft.top().first >= A[i])
        {
            while (sleft.size() > 0 && sleft.top().first >= A[i])
            {
                sleft.pop();
            }
            
            if (sleft.size() == 0)
            left.push_back(-1);
            else
            left.push_back(sleft.top().second);
        }
        
        sleft.push({A[i], i});
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        if (sright.size() == 0)
        right.push_back(n);
        
        else if (sright.size() > 0 && sright.top().first < A[i])
        right.push_back(sright.top().second);
        
        else if (sright.size() > 0 && sright.top().first >= A[i])
        {
            while (sright.size() > 0 && sright.top().first >= A[i])
            {
                sright.pop();
            }
            
            if (sright.size() == 0)
            right.push_back(n);
            else
            right.push_back(sright.top().second);
        }
        
        sright.push({A[i], i});
    }
    
    reverse(right.begin(), right.end());
    
    vector <int> area (n, 0);
    vector <int> width (n, 0);
    
    int mx = INT_MIN;
    
    for (int i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
        area[i] = width[i] * A[i];
        mx = max(mx, area[i]);
    }
    
    return mx;
    
}
