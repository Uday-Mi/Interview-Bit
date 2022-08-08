/*
Given a string A and integer B, what is maximal lexicographical string that can be made from A if you do atmost B swaps.



Problem Constraints
1 <= |A| <= 9

A contains only digits from 0 to 9.

1 <= B <= 5



Input Format
First argument is string A.

Second argument is integer B.



Output Format
Return a string, the naswer to the problem.



Example Input
Input 1:

A = "254"
B = 1
Input 2:

A = "254"
B = 2


Example Output
Output 1:

 524
Output 2:

 542


Example Explanation
Explanation 1:

 Swap 2 and 5.
Explanation 2:

Swap 2 and 5 then swap 4 and 2.
**/

string Solution::solve(string A, int B) {
    
    if (B == 0)
    return A;
    
    int n = A.size();
    
    int a = stoi(A);
    int mx = 0;
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string c = to_string(a);
            swap(c[i], c[j]);
            string str = solve(c, B - 1);
            int val = stoi(str);
            mx = max(val, mx);
        }
    }
    
    return to_string(mx);
    
}
