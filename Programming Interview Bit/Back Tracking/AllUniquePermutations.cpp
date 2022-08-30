/*
Given an array A of size N denoting collection of numbers that might contain duplicates, return all possible unique permutations.

NOTE: No 2 entries in the permutation sequence should be the same.



Input Format
Only argument is an integer array A of size N.


Output Format
Return a 2-D array denoting all possible unique permutation of the array.


Example Input
Input 1: 
A = [1, 1, 2]
Input 2: 
A = [1, 2]


Example Output
Output 1: 
[ [1, 1, 2]
  [1, 2, 1]
  [2, 1, 1] ]
Output 2: 
[ [1, 2]
  [2, 1] ]


Example Explanation
Explanation 1: 
All the possible unique permutation of array [1, 1, 2].
Explanation 2: 
All the possible unique permutation of array [1, 2].

**/

vector<vector<int> > Solution::permute(vector<int> &A) {
    
    int n = A.size();
    
    sort(A.begin(), A.end());
    
    vector <vector <int>> v;
    
    v.push_back(A);
    
    while (next_permutation(A.begin(), A.end()))
    {
        v.push_back(A);
    }
    
    return v;
    
}

//Code for next_permutation

/*
    vector <int> next_permutation (vector <int> &A)
    {
        int n = A.size();
        
        int k;
        int l;
        
        for (k = n - 2; k >= 0; k--)
        {
            if (A[k] < A[k + 1])
            break;
        }
        
        if (k < 0)
        reverse(A.begin(), A.end());
        
        else
        {
            for (int l = n - 1; l > k; l--)
            {
                if (A[l] > A[k])
                break;
            }
            
            swap(A[k], A[l]);
            reverse(A.begin() + k + 1, A.end());
        }
        
        return A;
    }
**/
