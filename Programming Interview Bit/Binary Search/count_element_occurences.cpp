/*
Given a sorted array of integers, find the number of occurrences of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return 0

**Example : **

Given [5, 7, 7, 8, 8, 10] and target value 8,

return 2.

PROBLEM APPROACH :

For complete solution, look at the hint.
**/

int Solution::findCount(const vector<int> &A, int B) {
    
    int lower = lower_bound(A.begin(), A.end(), B) - A.begin();
    int upper = upper_bound(A.begin(), A.end(), B) - A.begin();
    return upper - lower;
    
}
