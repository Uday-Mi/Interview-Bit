/*
Given an array A containing N integers, find the variance of the array. Return your answer up to 2 decimal points.


Problem Constraints

1 <= N <= 1000 1 <= A[i] <= 1000


Input Format

First argument is an integer, N, denoting the length of the input array Second line consists of N elements, separated by space


Output Format

Return a float value as specified in the question


Example Input

Input 1: N = 10 A = [99, 81, 4, 74, 9, 79, 45, 25, 44, 86]


Example Output

Output 1: 1034.64


Example Explanation

Mean = 54.6, simply apply the formula of variance to get 1034.64
**/

string Solution::solve(vector<int> &A) {
    
    int n = A.size();
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        sum = sum + A[i];
    }
    
    double avg = sum / (n * 1.0);
    
    double var = 0;
    
    for (int i = 0; i < n; i++)
    {
        var = var + pow(avg - A[i], 2);
    }
    
    var = var / n;
    
    var = round(var * 100) / 100;
    
    string str = to_string(var);
    
    size_t p = str.find('.');
    
    return str.substr(0, p + 3);
    
}
