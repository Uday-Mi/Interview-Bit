/*
Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array will not contain duplicates.

NOTE 1: Also think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
PROBLEM APPROACH:

Note: If you know the number of times the array is rotated, then this problem becomes trivial. If the number of rotation is x, then minimum element is A[x].

Lets look at how we can calculate the number of times the array is rotated.

Complete solution in the hints.
**/

/*
METHOD 1
**/

int Solution::findMin(const vector<int> &A) {
    
    int n = A.size();
    
    for (int i = 1; i < n - 1; i++)
    {
        if (A[i] < A[i - 1] && A[i] < A[i + 1])
        return A[i];
    }
    
    if (A[0] < A[n - 1])
    return A[0];
    return A[n - 1];
    
}

/*
METHOD 2
**/

int Solution::findMin(const vector<int> &A) {
    
    return *min_element(A.begin(), A.end());
  
}

