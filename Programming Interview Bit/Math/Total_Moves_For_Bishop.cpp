/*
Given the position of a Bishop (A, B) on an 8 * 8 chessboard.

Your task is to count the total number of squares that can be visited by the Bishop in one move.

The position of the Bishop is denoted using row and column number of the chessboard.



Problem Constraints
1 <= A, B <= 8



Input Format
First argument is an integer A denoting the row number of the bishop.

Second argument is an integer B denoting the column number of the bishop.



Output Format
Return an integer denoting the total number of squares that can be visited by the Bishop in one move.



Example Input
Input 1:

 A = 4
 B = 4


Example Output
Output 1:

 13
 **/


int Solution::solve(int A, int B) {
    
    int a = A;
    int b = B;
    int c = 0;
    while (a != 0 && b != 0)
    {
        a--;
        b--;
        if (a > 0 && b > 0)
        c++;
    }
    
    a = A;
    b = B;
    
    while (a != 0 && b != 9)
    {
        a--;
        b++;
        if (a > 0 && b < 9)
        c++;
    }
    
    a = A;
    b = B;
    
    while (a != 9 && b != 0)
    {
        a++;
        b--;
        if (a < 9 && b > 0)
        c++;
    }
    
    a = A;
    b = B;
    
    while (a != 9 && b != 9)
    {
        a++;
        b++;
        if (a < 9 && b < 9)
        c++;
    }
    
    return c;
    
}
