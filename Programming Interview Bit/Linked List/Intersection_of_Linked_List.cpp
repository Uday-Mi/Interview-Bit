/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Problem approach completely explained :

Complete code in the hints section.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    
    int lenA = 0;
    int lenB = 0;
    int tempLen = 0;
    int j = 0;
    
    typedef struct ListNode *Node;
    
    Node A_temp = A;
    Node B_temp = B;
    Node temp;
    
    while (A_temp != NULL)
    {
        lenA++;
        A_temp = A_temp -> next;
    }
    
    while (B_temp != NULL)
    {
        lenB++;
        B_temp = B_temp -> next;
    }
    
    if (lenA > lenB)
    {
        tempLen = lenA;
        lenA = lenB;
        lenB = tempLen;
        temp = A;
        A = B;
        B = temp;
    }
    
    j = 0;
    
    while (j < lenB - lenA)
    {
        B = B -> next;
        j++;
    }
    
    while (A != NULL && B != NULL)
    {
        if (A == B)
        {
            return A;
        }
        
        A = A -> next;
        B = B -> next;
    }
    
    return NULL;
}
