/*
Given a number N, find all prime numbers upto N ( N included ).

Example:

if N = 7,

all primes till 7 = {2, 3, 5, 7}

Make sure the returned array is sorted.

Problem Approach:

Complete code in the hint.


**/

vector<int> Solution::sieve(int A) {
    
    vector <int> v;
    int f = 1;
    for (int i = 1; i <= A; i = i + 1)
    {
        if (i == 2)
        {
            v.push_back(i);
            continue;
        }
        if (i % 2 == 0)
        continue;
        f = 1;
        if (i == 1)
        continue;
        int s = (int)sqrt(i);
        for (int j = 2; j <= s; j++)
        {
            if (i % j == 0)
            {
                f = 0;
                break;
            }
        }
        if (f == 1)
        v.push_back(i);
    }
    return v;
    
}
