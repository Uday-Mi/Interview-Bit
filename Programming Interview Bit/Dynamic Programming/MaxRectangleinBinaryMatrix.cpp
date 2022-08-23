/*
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

Bonus if you can solve it in O(n^2) or less.

Example :

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2)
**/

int MAH (vector <int> &arr, int size)
{
    vector <int> left;
    vector <int> right;
    
    stack <pair <int, int>> sleft;
    stack <pair <int, int>> sright;
    
    for (int i = 0; i < size; i++)
    {
        if (sleft.size() == 0)
        left.push_back(-1);
        
        else if (sleft.size() > 0 && sleft.top().first < arr[i])
        left.push_back(sleft.top().second);
        
        else if (sleft.size() > 0 && sleft.top().first >= arr[i])
        {
            while (sleft.size() > 0 && sleft.top().first >= arr[i])
            {
                sleft.pop();
            }
            
            if (sleft.size() == 0)
            {
                left.push_back(-1);
            }
            else
            {
                left.push_back(sleft.top().second);
            }
        }
        
        sleft.push({arr[i], i});
    }
    
    for (int i = size - 1; i >= 0; i--)
    {
        if (sright.size() == 0)
        {
            right.push_back(size);
        }
        
        else if (sright.size() > 0 && sright.top().first < arr[i])
        right.push_back(sright.top().second);
        
        else if (sright.size() > 0 && sright.top().first >= arr[i])
        {
            while (sright.size() > 0 && sright.top().first >= arr[i])
            {
                sright.pop();
            }
            
            if (sright.size() == 0)
            right.push_back(size);
            else
            right.push_back(sright.top().second);
        }
        
        sright.push({arr[i], i});
    }
    
    reverse(right.begin(), right.end());
    
    vector <int> width (size);
    vector <int> area (size);
    
    int mx = INT_MIN;
    
    for (int i = 0; i < size; i++)
    {
        width[i] = right[i] - left[i] - 1;
        area[i] = width[i] * arr[i];
        mx = max(mx, area[i]);
    }
    
    return mx;
    
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    
    int n = A.size();
    
    vector <int> sum (A[0].size(), 0);
    
    int mx = INT_MIN;
    
    for (int i = 0; i < n; i++)
    {
        int m = A[i].size();
        
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 0)
            sum[j] = 0;
          
            sum[j] = sum[j] + A[i][j];
        }
        
        mx = max(mx, MAH(sum, m));
    }
    
    return mx;
}
