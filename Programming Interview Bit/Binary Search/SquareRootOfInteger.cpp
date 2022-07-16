/*
Given an integer A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY.

NOTE: Do not use sort function from standard library. Users are expected to solve this in O(log(A)) time.



Input Format
The first and only argument given is the integer A.



Output Format
Return floor(sqrt(A))



Example Input
Input 1:

 11
Input 2:

 9


Example Output
Output 1:

 3
Output 2:

 3


Example Explanation
Explanation:

 When A = 11 , square root of A = 3.316. It is not a perfect square so we return the floor which is 3.
 When A = 9 which is a perfect square of 3, so we return 3.
 **/

int Solution::sqrt(int A) {
    
    long long int l = 0; 
    long long int h = A;
    
    long long int mid = (l + h) / 2;
    
    while (l <= h)
    {
        mid = (l + h) / 2;
        
        long long int a = mid * mid;
        long long int b = (mid + 1) * (mid + 1);
        
        if (A == a)
        return mid;
        
        if (A < b && A > a)
        return mid;
        
        if (A < a)
        h = mid - 1;
        
        if (A > a)
        l = mid + 1;
    }
    
    return mid;
    
}
