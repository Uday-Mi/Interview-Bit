/*
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
Sample Input:

[3 4 1 4 1]

Sample Output:

1

If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1
**/

//METHOD 1

int Solution::repeatedNumber(const vector<int> &A) {
    
    int n = A.size();
    vector <int> v = A;
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < n - 1; i++)
    {
        int a = v[i];
        int b = v[i + 1];
        
        if (a == b)
        return a;
    }
    
    return -1;
    
}


//METHOD 2

#include <bitset>

int Solution::repeatedNumber(const vector<int> &A) {
    
    int n = A.size();
    
    bitset <10000000> arr;
    
    for (int i = 0; i < n; i++)
    {
        if (arr[A[i]] == 1)
        return A[i];
        else
        arr[A[i]] = 1;
    }
    
    return -1;
}
