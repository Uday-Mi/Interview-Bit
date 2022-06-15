/*
vector<int> Solution::maxset(vector<int> &A) {
    
    vector <int> x;
    vector <int> w;
    long sum = 0;
    long max = -1;
    
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] >= 0)
        {
            w.push_back(A[i]);
            sum = sum + A[i];
            if (max < sum)
            {
                max = sum;
                x = w;
            }
        }
        else
        {
            if (sum > max)
            {
                max = sum;
                x = w;
            }
            if (sum == max)
            {
                if (w.size() > x.size())
                {
                    x = w;
                }
            }
            sum = 0;
            w.clear();
        }
    }
    return x;
    
}
**/

int multiply (int x, int fact[], int sz);

string Solution::solve(int A) {
    
    int max = 500;
    int res[max];
    res[0] = 1;
    int res_size = 1;
    
    for (int x = 2; x <= A; x++)
    {
        res_size = multiply(x, res, res_size);
    }
    
    string str = "";
    for (int i = res_size - 1; i >= 0; i--)
    {
        str = str + to_string(res[i]);
    }
    
    return str;
    
}

int multiply (int x, int fact[], int sz)
{
    int carry = 0; 
    for (int i = 0; i < sz; i++)
    {
        int prod = fact[i] * x + carry;
        fact[i] = prod % 10;
        carry = prod / 10;
    }
    
    while (carry)
    {
        fact[sz] = carry % 10;
        carry = carry / 10;
        sz++;
    }
    
    return sz;
}
