/*
Given a set of digits (A) in sorted order, find how many numbers of length B are possible whose value is less than number C.
NOTE: All numbers can only have digits from the given set.  

Examples:

Input:
  0 1 5

  1

  2

Output:

  2 (0 and 1 are possible)  


Input:
  0 1 2 5

  2

  21

Output:
  5 (10, 11, 12, 15, 20 are possible)

Constraints:

1 <= B <= 9, 0 <= C <= 1e9 & 0 <= A[i] <= 9
**/

int Solution::solve(vector<int> &A, int B, int C) {
    
    int n = A.size();
    int c = C;
    int l = 0;
    int ans = 0;
    
    if (n == 0 || B == 0)
    return 0;
    
    while (C != 0)
    {
        l++;
        C = C / 10;
    }
    
    if (l < B)
    return 0;
    
    if (l > B)
    {
        if (A[0] == 0)
        {
            ans = (n - 1) * pow(n, B - 1);
            if (B == 1)
            ans++;
        }
        else
        ans = pow(n, B);
        return ans;
    }
    
    if (l == B)
    {
        if (B == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (A[i] < c)
                ans++;
            }
            return ans;
        }
        vector <int> temp(B);
        
        for (int i = B - 1; i >= 0; i--)
        {
            temp[i] = c % 10;
            c = c / 10;
        }
        
        int count = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (A[i] == 0)
            continue;
            if (A[i] > temp[0])
            break;
            count++;
        }
        
        ans = ans + (count * pow(n, B - 1));
        
        int flag = 0;
        int j = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (A[i] == temp[0])
            {
                flag = 1;
            }
        }
        
        j++;
        
        while (flag == 1 && j <= B - 1)
        {
            flag = 0;
            int countx = 0;
            
            for (int i = 0; i < n; i++)
            {
                if (A[i] > temp[j])
                countx++;
                
                if (A[i] == temp[j])
                flag = 1;
            }
            
            ans = ans - countx * pow(n, B - j - 1);
            j++;            
        }
        
        if (j == B && flag == 1)
        ans--;
        
        return ans;
    }
    
}
