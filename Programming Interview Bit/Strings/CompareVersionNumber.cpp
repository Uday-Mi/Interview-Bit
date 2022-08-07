/*
Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4
**/

int Solution::compareVersion(string A, string B) {
    
    double n = A.size();
    double m = B.size();
    
    vector <double> v;
    vector <double> w;
    
    double a = 0;
    
    for (int i = 0; i < n; i++)
    {
        char ch = A[i];
        
        if (ch == '.')
        {
            v.push_back(a);
            a = 0;
        }
        
        else
        {
            a = a * 10 + (ch - '0');
        }
    }
    
    v.push_back(a);    
    a = 0;
    
    for (int i = 0; i < m; i++)
    {
        char ch = B[i];
        
        if (ch == '.')
        {
            w.push_back(a);
            a = 0;
        }
        
        else
        {
            a = a * 10 + (ch - '0');
        }
    }
    
    w.push_back(a);
    a = 0;
    
    int x = v.size();
    int y = w.size();
    
    int i = 0;
    int j = 0;
    
    while (i < x && j < y)
    {
        double b = v[i];
        double c = w[i];
        
        if (b > c)
        return 1;
        
        if (b < c)
        return -1;
        
        i++;
        j++;
    }
    
    if (x > y)
    {
        for (; i < x; i++)
        {
            if (v[i] > 0)
            return 1;
        }
    }
    
    if (x < y)
    {
        for (; j < y; j++)
        {
            if (w[i] > 0)
            return -1;
        }
    }
    
    return 0;
        
}
