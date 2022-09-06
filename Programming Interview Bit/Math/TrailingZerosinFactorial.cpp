/*
Given an integer A, return the number of trailing zeroes in A!.

Note: Your solution should be in logarithmic time complexity.



Problem Constraints
0 <= A <= 10000000



Input Format
First and only argumment is integer A.



Output Format
Return an integer, the answer to the problem.



Example Input
Input 1:

 A = 4
Input 2:

 A = 5


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 4! = 24
Explanation 2:

 5! = 120
 **/

int Solution::trailingZeroes(int A) {
    
    int zero = 0;
    
    for (int i = 5; i <= A; i = i + 5)
    {
        int j = i;
        
        while (j % 5 == 0 && j > 0)
        {
            j = j / 5;
            zero++;
        }
    }
    
    return zero;
    
}
