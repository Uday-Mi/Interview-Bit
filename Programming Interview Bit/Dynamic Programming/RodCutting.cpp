/*
There is a rod of length N lying on x-axis with its left end at x = 0 and right end at x = N. Now, there are M weak points on this rod denoted by positive integer values(all less than N) A1, A2, …, AM. You have to cut rod at all these weak points. You can perform these cuts in any order. After a cut, rod gets divided into two smaller sub-rods. Cost of making a cut is the length of the sub-rod in which you are making a cut.

Your aim is to minimise this cost. Return an array denoting the sequence in which you will make cuts. If two different sequences of cuts give same cost, return the lexicographically smallest.

Notes:

Sequence a1, a2 ,…, an is lexicographically smaller than b1, b2 ,…, bm, if and only if at the first i where ai and bi differ, ai < bi, or if no such i found, then n < m.
N can be upto 109.
For example,

N = 6
A = [1, 2, 5]

If we make cuts in order [1, 2, 5], let us see what total cost would be.
For first cut, the length of rod is 6.
For second cut, the length of sub-rod in which we are making cut is 5(since we already have made a cut at 1).
For third cut, the length of sub-rod in which we are making cut is 4(since we already have made a cut at 2).
So, total cost is 6 + 5 + 4.

Cut order          | Sum of cost
(lexicographically | of each cut
 sorted)           |
___________________|_______________
[1, 2, 5]          | 6 + 5 + 4 = 15
[1, 5, 2]          | 6 + 5 + 4 = 15
[2, 1, 5]          | 6 + 2 + 4 = 12
[2, 5, 1]          | 6 + 4 + 2 = 12
[5, 1, 2]          | 6 + 5 + 4 = 15
[5, 2, 1]          | 6 + 5 + 2 = 13


So, we return [2, 1, 5].
**/

long long int MinCost (int start, int end, vector <int> &weak_pt, vector <vector <long long int>> &dp, vector <vector <int>> &cutting_pos)
{
    if (abs(start - end) <= 1)
    return 0;
    
    if (dp[start][end] != -1)
    return dp[start][end];
    
    long long int min_cost = -1;
    
    for (int cut_pos = start + 1; cut_pos < end; cut_pos++)
    {
        long long int cost_for_cut = weak_pt[end] - weak_pt[start];
        long long int curr_cost = cost_for_cut + MinCost(start, cut_pos, weak_pt, dp, cutting_pos) + MinCost(cut_pos, end, weak_pt, dp, cutting_pos);
        
        if (curr_cost < min_cost || min_cost == -1)
        {
            min_cost = curr_cost;
            cutting_pos[start][end] = cut_pos;
        }
    }
    
    return dp[start][end] = min_cost;
}

void Fill_Order (int start, int end, vector <int> &order, vector <vector <int>> &cutting_pos, vector <int> &weak_pt)
{
    if (abs(start - end) <= 1)
    return;
    
    order.push_back(weak_pt[cutting_pos[start][end]]);
    Fill_Order(start, cutting_pos[start][end], order, cutting_pos, weak_pt);
    Fill_Order(cutting_pos[start][end], end, order, cutting_pos, weak_pt);
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    
    B.push_back(0);
    B.push_back(A);
    
    sort(B.begin(), B.end());
    
    int m = B.size();
    
    vector <vector <long long int>> dp(m + 1, vector <long long int> (m + 1, -1));
    vector <vector <int>> cutting_pos(m + 1, vector <int> (m + 1));
    
    long long int x = MinCost(0, m - 1, B, dp, cutting_pos);
    
    vector <int> order;
    Fill_Order(0, m - 1, order, cutting_pos, B);
    
    return order;
    
}
