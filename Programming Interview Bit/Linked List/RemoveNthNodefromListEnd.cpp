/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    int c = 0;
    
    ListNode *a = A;
    
    while (a != NULL)
    {
        c++;
        a = a -> next;
    }
    
    a = A;
    ListNode *prev = a;
    
    int x = c - B;
    
    if (B > c)
    x = 0;
    
    for (int i = 0; i < x; i++)
    {
        a = a -> next;
        
        if (i > 0)
        prev = prev -> next;
    }
    
    if (x != 0)
    {
        prev -> next = a -> next;
        free(a);
    }
    
    if (x == 0)
    {
        a = A -> next;
        free(A);
        return a;
    }
    
    return A;
    
}
