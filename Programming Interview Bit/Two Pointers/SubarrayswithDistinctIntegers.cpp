/*
Given an array A of positive integers,call a (contiguous,not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly B.

(For example: [1, 2, 3, 1, 2] has 3 different integers 1, 2 and 3)

Return the number of good subarrays of A.



Problem Constraints
1 <= |A| <= 40000

1 <= A[i] <= |A|

1 <= B <= |A|



Input Format
The first argument given is the integer array A.

The second argument given is an integer B.



Output Format
Return an integer denoting the number of good subarrays of A.



Example Input
Input 1:

 A = [1, 2, 1, 2, 3]
 B = 2
Input 2:

 A = [1, 2, 1, 3, 4]
 B = 3


Example Output
Output 1:

 7
Output 2:

 3


Example Explanation
Explanation 1:

  Subarrays formed with exactly 2 different integers: [1, 2], [2, 1], [1, 2], [2, 3], [1, 2, 1], [2, 1, 2], [1, 2, 1, 2].
Explanation 2:

  Subarrays formed with exactly 3 different integers: [1, 2, 1, 3], [2, 1, 3], [1, 3, 4].
**/

int find (vector <int> &A, int B)
{
    map <int, int> mp;
     
    int ans = 0;
    int j = 0;
     
    int n = A.size();
    
    for (int i = 0; i < n; i++)
    {
        mp[A[i]]++;
        
        while (mp.size() > B)
        {
            mp[A[j]]--;
            
            if (mp[A[j]] == 0)
            mp.erase(A[j]);
            
            j++;
        }
        
        ans = ans + i - j + 1;
    }
    
    return ans;
} 

int Solution::solve(vector<int> &A, int B) {
    
    return find(A, B) - find(A, B - 1);
    
}
