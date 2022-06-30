/*
Reverse a linked list using recursion.

Example :

Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.

PROBLEM APPROACH :

Complete solution code in the hints
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    

    if(A->next==NULL || A==NULL)
    {
        return A;
    }
   ListNode* head= reverseList(A->next);
    A->next->next=A;
    A->next = NULL;
    return head;
    
}
