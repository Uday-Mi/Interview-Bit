/*
Merge two sorted linked lists and return it as a new list. 

The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    ListNode *list;
    
    if (A == NULL)
    {
        return B;
    }
    
    if (B == NULL)
    {
        return A;
    }
    
    if (A -> val < B -> val)
    {
        list = A;
        A = A -> next;
    }
    
    else
    {
        list = B;
        B = B -> next;
    }
    
    ListNode *ptr = list;    
    
    while (A != NULL && B != NULL)
    {
        int a = A -> val;
        int b = B -> val;
        
        if (a <= b)
        {
            list -> next = A;
            list = list -> next;
            A = A -> next;
        }
        
        if (a >= b)
        {
            list -> next = B;
            list = list -> next;
            B = B -> next;
        }
    }
    
    while (A != NULL)
    {
        list -> next = A;
        A = A -> next;
        list = list -> next;
    }
    
    while (B != NULL)
    {
        list -> next = B;
        B = B -> next;
        list = list -> next;
    }
    
    return ptr;
    
}
