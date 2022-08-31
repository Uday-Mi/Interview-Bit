/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
**/

bool comp (string a, string b)
{
    return a + b > b + a;
}

string Solution::largestNumber(const vector<int> &A) {
    
    int n = A.size();
    
    vector <string> v;
    
    for (int i = 0; i < n; i++)
    {
        v.push_back(to_string(A[i]));
    }
    
    sort(v.begin(), v.end(), comp);
    
    string str  = "";
    
    for (int i = 0; i < n; i++)
    {
        str += v[i];
    }
    
    if (v[0] == "0")
    return "0";
    
    return str;
    
}
