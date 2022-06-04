/*
Given an array of integers A representing the length of ropes.

You need to connect these ropes into one rope. The cost of connecting two ropes is equal to the sum of their lengths.

Find and return the minimum cost to connect these ropes into one rope.

Constraints

1 <= length of the array <= 100000
1 <= A[i] <= 1000
Input Format

The only argument given is the integer array A.
Output Format

Return an integer denoting the minimum cost to connect these ropes into one rope.
Sample Input

A = [1, 2, 3, 4, 5]
Sample Output

33
**/

int solve(vector<int> &A){
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int cost = 0;
    
    // insert all elements in the queue
    for(int x:A)
    {
        pq.push(x);
    }
    
    // keep on removing elements from the queue untill there is one element in the queue
    while(pq.size() != 1){
        
        // Take the two ropes with smallest length
        int l1 = pq.top();
        pq.pop();
        int l2 = pq.top();
        pq.pop();
        
        // cost of combining these two ropes is l1 + l2.
        cost += l1 + l2;
        
        // add the newly formed rope of length l1 + l2 to the queue.
        pq.push(l1 + l2);
    }
    
    return cost;    
}
