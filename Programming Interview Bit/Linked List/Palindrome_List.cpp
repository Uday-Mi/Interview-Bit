/*
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// typedef struct ListNode *Node;

int Solution::lPalin(ListNode* A) {
    
    typedef struct ListNode *Node;    
    
    vector <int> v;
    while (A != NULL)
    {
        v.push_back(A -> val);
        A = A -> next;
    }
    
    int i = 0;
    int m = v.size();
    int j = m - 1;
    
    for (i = 0; i < m; i++)
    {
        if (v[i] != v[j])
        return 0;
        j--;
    }
    return 1;
}
