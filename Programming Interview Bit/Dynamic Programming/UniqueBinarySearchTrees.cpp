/*
Given A, generate all structurally unique BST’s (binary search trees) that store values 1…A.

Input Format:

The first and the only argument of input contains the integer, A.
Output Format:

Return a list of tree nodes representing the generated BST's.
Constraints:

1 <= A <= 15
Example:

Input 1:
    A = 3

Output 1:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
 
vector <int> inorder;

vector <TreeNode*> rec (int l, int r)
{
    if (l > r)
    return {NULL};
    
    vector <TreeNode*> ans;
    
    for (int i = l; i <= r; i++)
    {
        vector <TreeNode*> leftNode = rec(l, i - 1);
        vector <TreeNode*> rightNode = rec(i + 1, r);
        
        for (auto ll : leftNode)
        {
            for (auto rr : rightNode)
            {
                TreeNode *temp = new TreeNode (inorder[i]);
                temp -> left = ll;
                temp -> right = rr;
                ans.push_back(temp);
            }
        }
    }
    
    return ans;
}

vector<TreeNode*> Solution::generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    inorder.clear();
    
    for (int i = 1; i <= A; i++)
    {
        inorder.push_back(i);
    }
    
    return rec(0, A - 1);
    
}
