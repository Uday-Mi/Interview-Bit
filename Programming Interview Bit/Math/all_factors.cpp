/*
Given a number N, find all factors of N.

Example:

N = 6 
factors = {1, 2, 3, 6}
Make sure the returned array is sorted.

Problem Approach:

VIDEO : https://www.youtube.com/watch?v=dolcMgiJ7I0

Complete code in the hint.
**/

vector<int> Solution::allFactors(int A) {
    vector <int> v;
    int n = (int)sqrt(A);
    for (int i = 1; i <= n; i++)
    {
        if (A % i == 0)
        {
            v.push_back(i);
            int m = A / i;
            if (m != i)
            v.push_back(m);
        }
    }
    sort(v.begin(), v.end());
    return v;
}
