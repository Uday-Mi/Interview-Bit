/*
You are given a function sortArray which takes an array of pairs, sort the given array in ascending order of their sum.
**/

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

bool comp (pair <int, int> a, pair <int, int> b)
{
    int s1 = a.first + a.second;
    int s2 = b.first + b.second;
    if (s1 < s2)
        return true;
    return false;
}

void sortArray(vector<pair<int, int>> &A){
    
    sort(A.begin(), A.end(), comp);
    // for (int i = 0; i < A.size(); i++)
    // {
    //     cout << A[i].first << " " << A[i].second << endl;
    // }

}

