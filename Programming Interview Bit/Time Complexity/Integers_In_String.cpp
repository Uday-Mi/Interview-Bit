/*
Given a string A, consisting of comma-separated positive integers.
Extract the given integers from the string and return an integer array consisting of the integers present in the string.

Note: All given integers will fit in a 32-bit signed integer.


Problem Constraints
1 <= |A| <= 105


Input Format
The first and only argument is a string A.


Output Format
Return an integer array.
The array should contain all the integers in the same order as they appear in the string.


Example Input
Input 1:
A = "1,2,3"
Input 2:

A = "1,99,3"


Example Output
Output 1:
[1, 2, 3]
Output 2:

[1, 99, 3]


Example Explanation
Explanation 1:
The array is given in Example output.
Explanation 2:

The array is given in Example output.
**/

vector<int> Solution::solve(string A) {

    vector <int> v;
    stringstream ss(A);
    string str = "";
    while(getline(ss, str, ','))
    {
        int a = 0;;
        for (int i = 0; i < str.size(); i++)
        {
            a = a * 10 + (str[i] - '0');
        }
        v.push_back(a);
    }
    return v;

}
