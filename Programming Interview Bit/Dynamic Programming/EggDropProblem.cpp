/*
You are given A eggs, and you have access to a building with B floors from 1 to B.

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor C with 0 <= C <= B  such that any egg dropped at a floor higher than C will break, and any egg dropped at or below floor C will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= B). 

Your goal is to know with certainty what the value of C is.

What is the minimum number of moves that you need to know with certainty what C is, regardless of the initial value of C



Problem Constraints

    1 <= A <= 100
    1 <= B <= 104



Input Format

First Argument is an integer A denoting number of eggs.

Second Argument is an integer B denoting number of floors.



Output Format

Return an integer denoting the Minimum number of moves.


Example Input

Input 1:

 A = 1
 B = 2

Input 2:

 A = 2
 B = 10



Example Output

Output 1:

 2

Output 2:

 4 



Example Explanation

Explanation 1:

 Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
 Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
 If it didn't break, then we know with certainty F = 2.
 Hence, we needed 2 moves in the worst case to know what F is with certainty.

**/

int t[101][10001];

int ans(int e, int f)
{
    if (e == 1)
    return f;
    
    if (f == 0 || f == 1)
    return f;
    
    if (t[e][f] != -1)
    return t[e][f];
    
    int a = INT_MAX;
    
    int left = 0;
    int right = 0;
    
    int lo = 1;
    int hi = f;
    
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        
        if (t[e - 1][mid - 1] != -1)
        left = t[e - 1][mid - 1];
        else
        {
            left = ans(e - 1, mid - 1);
            t[e - 1][mid - 1] = left;
        }
        
        if (t[e][f - mid] != -1)
        right = t[e][f - mid];
        else
        {
            right = ans(e, f - mid);
            t[e][f - mid] = right;
        }
        
        int temp = 1 + max(left, right);
        
        a = min(a, temp);
        
        if (right > left)
        lo = mid + 1;
        else
        hi = mid - 1;
    }
    
    return t[e][f] = a;
}

int Solution::solve(int A, int B) {
    
    memset(t, -1, sizeof(t));
    
    return ans(A, B);
    
}
