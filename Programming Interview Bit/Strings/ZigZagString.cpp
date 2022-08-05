/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **

ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.
**/

string Solution::convert(string A, int B) {
    
    int n = A.size();
    
    string s = "";
    
    if (B == 1)
    return A;
    
    vector <char> v[B];

    int j = 0;
    int x = 0;
    
    for (int i = 0; i < n; i++)
    {
        v[j].push_back(A[i]);
        
        if (j == 0)
        x = 1;
        if (j == B - 1)
        x = 0;

        x ? j++ : j--;
    }
    
    for (j = 0; j < B; j++)
    {
        for (int i = 0; i < v[j].size(); i++)
        {
            s = s + v[j][i];
        }
    }
    
    return s;
    
}
