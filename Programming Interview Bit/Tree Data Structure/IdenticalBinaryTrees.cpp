/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return  0 / 1  ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 
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
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    
    if (A == NULL && B == NULL)
    return 1;
    
    if ((A == NULL && B != NULL) || (A != NULL && B == NULL))
    return 0;
    
    if (A -> val != B -> val)
    return 0;
    
    int left = isSameTree(A -> left, B -> left);
    int right = isSameTree(A -> right, B -> right);
    
    if (left && right)
    return 1;
    
    return 0;
    
}
