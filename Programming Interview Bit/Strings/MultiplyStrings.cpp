/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer.

For example, 

given strings "12", "10", your answer should be “120”.

NOTE : DO NOT USE BIG INTEGER LIBRARIES ( WHICH ARE AVAILABLE IN JAVA / PYTHON ). 

We will retroactively disqualify such submissions and the submissions will incur penalties.
**/

string Solution::multiply(string A, string B) {
    
    int n = A.size();
    int m = B.size();
    
    if (A == "0" || B == "0")
    return "0";
    
    vector <int> v (n + m, 0);
    
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            v[i + j + 1] = v[i + j + 1] + (A[i] - '0') * (B[j] - '0');
            v[i + j] = v[i + j] + v[i + j + 1] / 10;
            v[i + j + 1] = v[i + j + 1] % 10;
        }
    }
    
    string str = "";
    int x = v.size();
    int i = 0;
    
    while (v[i] == 0 && i < x)
    {
        i++;
    }
    
    for (; i < x; i++)
    {        
        char ch = v[i] + '0';
        str = str + ch;
    }
    
    return str;
    
}
