/*
Given an integer array A of size N.

You need to check that whether there exist a element which is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it.

If it exists return 1 else return 0.

NOTE:

Do not consider the corner elements i.e A[0] and A[N-1] as the answer.


Problem Constraints
3 <= N <= 105

1 <= A[i] <= 109



Input Format
First and only argument is an integer array A containing N integers.



Output Format
Return 1 if there exist a element that is strictly greater than all the elements on left of it and strictly  smaller than all the elements on right of it else return 0.



Example Input
Input 1:

 A = [5, 1, 4, 3, 6, 8, 10, 7, 9]
Input 2:

 A = [5, 1, 4, 4]


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 A[4] = 6 is the element we are looking for.
 All elements on left of A[4] are smaller than it and all elements on right are greater.
Explanation 2:

 No such element exits.
 **/

/*
I solved it using two methods.
The first method is slow. In that I used C++ STL Libraries, which are having high time complexity. However, the output obtained is correct.
The second method is the optimised method.
**/

/* METHOD 1 **/

int Solution::perfectPeak(vector<int> &A) {
    
    int n = A.size();
    
    vector <int> v;
    
    for (int i = 1; i < n - 1; i++)
    {
        v = A;
        
        vector <int> :: iterator it = v.begin();
        advance(it, i);
        
        sort(v.begin(), it);
        A = v;
        
        if (v[i - 1] >= v[i])
        {
            continue;
        } 
        
        advance(it, 1);
        sort(it, v.end());
        
        if (v[i] >= v[i + 1])
        {
            continue;
        }
        
        return 1;
    }
    return 0;
}

/* METHOD 2  **/

int Solution::perfectPeak(vector<int> &A) {
    
    int n = A.size();
    
    vector <int> left_max(n);
    vector <int> right_min(n);
    int max = A[0];
    int min = A[n - 1];
    int j = n - 1;
    
    for (int i = 0 ; i < n; i++)
    {
        if (max < A[i])
        max = A[i];
        if (min > A[j])
        min = A[j];
        left_max[i] = max;
        right_min[j] = min;
        j--;
    }
    
    for (int i = 1; i < n - 1; i++)
    {
        int a = A[i];
        if (a > left_max[i - 1] && a < right_min[i + 1])
        return 1;
    }
    return 0;
    
}
