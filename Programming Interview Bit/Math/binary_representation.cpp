/*
Given a number N >= 0, find its representation in binary.

Example:

if N = 6,

binary form = 110

Problem Approach:

Complete code in the hint.
**/

string Solution::findDigitsInBinary(int A) {
    
    string str = "";
    if (A == 0)
    return "0";
    while (A != 0)
    {
        int d = A % 2;
        A = A / 2;
        str = to_string(d) + str;
        
    }
    return str;
}
