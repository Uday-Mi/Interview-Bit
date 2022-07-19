/*
Given a sentence represented as an array A of strings that contains all lowercase alphabets.
Chech if it is a pangram or not.
A pangram is a unique sentence in which every letter of the lowercase alphabet is used at least once.


Problem Constraints
1 <= |A| <= 105
1 <= Ai <= 5


Input Format
Given an array of strings A.


Output Format
Return an integer.


Example Input
Input 1:
A = ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"]
Input 2:

A = ["interviewbit", "scaler"]




Example Output
Output 1:
1
Output 2:

0


Example Explanation
Explanation 1:
We can check that all english alphabets are present in given sentence.
Explanation 2:

Not all english alphabets are present.
**/

#include <bitset>

int Solution::solve(vector<string> &A) {
    
    int n = A.size();
    
    bitset <26> bit;
    
    for (int i = 0; i < n; i++)
    {
        string str = A[i];
        for (int j = 0; j < str.size(); j++)
        {
            char ch = str[j];
            int a = ch - 97;
            bit[a] = 1;
        }
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (bit[i] == 0)
        return 0;
    }
    return 1;
    
}
