/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the maximum value of j - i;



Example Input
Input 1:

 A = [3, 5, 4, 2]


Example Output
Output 1:

 2


Example Explanation
Explanation 1:

 Maximum value occurs for pair (3, 4).
 **/

//METHOD 1

int Solution::maximumGap(const vector<int> &A) {
    
    vector <pair <int, int>> v;
    
    int n = A.size();
    
    for (int i = 0; i < n; i++)
    {
        v.push_back({A[i], i});
    }
    
    sort (v.begin(), v.end());
    
    int max1 = v[0].second;
    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        max1 = min(max1, v[i].second);
        ans = max(ans, v[i].second - max1);
    }
    return ans;
}


//METHOD 2

int Solution::maximumGap(const vector<int> &A) {
    
    int n = A.size();
    int right[n];
    right[n - 1] = A[n - 1];
    
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], A[i]);
    }
    
    int ans = 0;
    int i = 0;
    int j = 0;
    
    while (i < n && j < n)
    {
        if (A[i] <= right[j])
        {
            ans = max(ans, j - i);
            j++;
        }
        
        else
        i++;
    }
    
    return ans
}

