/*
Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?

Operands are only true and false.

Return the number of ways to evaluate the expression modulo 103 + 3.



Input Format:

The first and the only argument of input will contain a string, A.

The string A, may contain these characters:
    '|' will represent or operator 
    '&' will represent and operator
    '^' will represent xor operator
    'T' will represent true operand
    'F' will false
Output:

Return an integer, representing the number of ways to evaluate the string.
Constraints:

1 <= length(A) <= 150
Example:

Input 1:
    A = "T|F"

Output 1:
    1

Explanation 1:
    The only way to evaluate the expression is:
        => (T|F) = T 

Input 2:
    A = "T^T^F"
    
Output 2:
    0
    
Explanation 2:
    There is no way to evaluate A to a true statement.
**/

unordered_map <string, int> mp;

int solve (string str, int i, int j, bool isTrue)
{
    if (i > j)
    return 0;
    
    if (i == j)
    {
        if (isTrue == true)
        return str[i] == 'T';
        else
        return str[i] == 'F';
    }
    
    string key = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
    
    if (mp.find(key) != mp.end())
    return mp[key];
    
    int ans = 0;
    
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int lt = 0;
        int rt = 0;
        int lf = 0;
        int rf = 0;
        
        string klt = to_string(i) + " " + to_string(k - 1) + " " + to_string(true);
        string krt = to_string(k + 1) + " " + to_string(j) + " " + to_string(true);
        string krf = to_string(k + 1) + " " + to_string(j) + " " + to_string(false);
        string klf = to_string(i) + " " + to_string(k - 1) + " " + to_string(false);
        
        if (mp.find(klt) != mp.end())
        lt = mp[klt];
        else
        lt = solve(str, i, k - 1, true);
        
        if (mp.find(krt) != mp.end())
        rt = mp[krt];
        else
        rt = solve(str, k + 1, j, true);
        
        if (mp.find(krf) != mp.end())
        rf = mp[krf];
        else
        rf = solve(str, k + 1, j, false);
        
        if (mp.find(klf) != mp.end())
        lf = mp[klf];
        else
        lf = solve(str, i, k - 1, false);
        
        if (str[k] == '&')
        {
            if (isTrue == true)
            ans = ans + (lt * rt);
            else
            ans = ans + (lt * rf) + (lf * rt) + (lf * rf);
        }
        
        if (str[k] == '|')
        {
            if (isTrue == true)
            ans = ans + (lt * rt) + (lf * rt) + (lt * rf);
            else
            ans = ans + (lf * rf);
        }
        
        if (str[k] == '^')
        {
            if (isTrue == true)
            ans = ans + (lt * rf) + (lf * rt);
            else
            ans = ans + (lt * rt) + (lf * rf);
        }
        
        
    }
    return mp[key] = ans % 1003;
}

int Solution::cnttrue(string A) {
    
    int n = A.size();
    
    mp.clear();
    
    return solve(A, 0, n - 1, true) % 1003;
    
}
