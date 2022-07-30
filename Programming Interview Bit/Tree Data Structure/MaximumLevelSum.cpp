/*
Given a Binary Tree denoted by root node A having integer value on nodes. You need to find maximum sum level in it.



Problem Constraints
1 <= number of nodes <= 105

1 <= value on nodes <= 105



Input Format
First and only argument is a root node of Binary Tree A.



Output Format
Return an integer denoting the maximum sum level in the tree.



Example Input
Input 1:

 Tree:      4
          /   \
         2     5
        / \   / \
       1  3  2   6
Input 2:

 Tree:      1
          /   \
         2     3
       /  \     \
      4    5     8
                / \
               6   7  


Example Output
Output 1:

 12
Output 2:

 17


Example Explanation
Explanation 1:

 Sum of all nodes of 0'th level is 4 
 Sum of all nodes of 1'th level is 7
 Sum of all nodes of 2'th level is 12
 Hence maximum sum is 12
Explanation 2:

 Sum of all nodes of 0'th level is 1
 Sum of all nodes of 1'th level is 5
 Sum of all nodes of 2'th level is 17
 Sum of all nodes of 3'th level is 13
 Hence maximum sum is 17
 **/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int sumLevelOrder (TreeNode *A)
{
    if (A == NULL)
    return 0;
    
    queue <TreeNode*> q;
    
    q.push(A);
    
    int sum = 0;
    int m = INT_MIN;
    
    while (q.empty() != true)
    {
        int n = q.size();
        sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            sum = sum + temp -> val;
            q.pop();
        
            if (temp -> left != NULL)
            {
                q.push(temp -> left);
            }
        
            if (temp -> right != NULL)
            {
                q.push(temp -> right);
            }
        }
        m = max(sum, m);
        
    }
    return m;
}
 
int Solution::solve(TreeNode* A) {
    
    int m = sumLevelOrder(A);
    return m;
    
}
