/*
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.

If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order.

Note:

1. The replacement must be in-place, do **not** allocate extra memory.
2. DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of Library functions will disqualify your submission retroactively and will give you penalty points.
Input Format:

The first and the only argument of input has an array of integers, A.
Output Format:

Return an array of integers, representing the next permutation of the given array.
Constraints:

1 <= N <= 5e5
1 <= A[i] <= 1e9
Examples:

Input 1:
    A = [1, 2, 3]

Output 1:
    [1, 3, 2]

Input 2:
    A = [3, 2, 1]

Output 2:
    [1, 2, 3]

Input 3:
    A = [1, 1, 5]

Output 3:
    [1, 5, 1]

Input 4:
    A = [20, 50, 113]

Output 4:
    [20, 113, 50]
    **/

/*
If you are not still clear with what exactly has to be done, I am attaching a link, where you could find more details.
https://www.interviewbit.com/blog/next-permutation-problem/

**/

vector<int> Solution::nextPermutation(vector<int> &A) {
    
    int n = A.size();
    int k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (A[k] < A[k + 1])
        {
            break;
        }
    }
    
    if (k < 0)
    {
        reverse(A.begin(), A.end());
    }
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (A[l] > A[k])
            break;
        }
        swap(A[k], A[l]);
        reverse(A.begin() + k + 1, A.end());
    }
    return A;
}
