/*
Write a function that takes an integer and returns the number of 1 bits it has.


Problem Constraints
0 <= A <= 4294967295


Input Format
First and only argument contains integer A


Output Format
Return an integer as the answer


Example Input
Input1:
    11


Example Output
Output1:
3


Example Explanation
Explaination1:
11 is represented as 1101 in binary 
**/

int Solution::numSetBits(unsigned int A) {
    
    int c = 0;
    
    while (A != 0)
    {
        int rem = A % 2;
        if (rem == 1)
        c++;
        A = A / 2;
    }
    
    return c;
    
}
