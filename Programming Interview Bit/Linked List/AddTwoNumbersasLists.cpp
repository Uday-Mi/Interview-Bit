/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list

So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/
 
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    if (A == NULL)
    return B;
    
    if (B == NULL)
    return A;
    
    int carry = 0;
    int sum = 0;
    
    ListNode *dummy = new ListNode(0);
    ListNode *head = dummy;
    
    while (A != NULL || B != NULL || carry == 1)
    {
        sum = 0;
        if (A != NULL)
        {
            sum = sum + A -> val;
            A = A -> next;
        }
        
        if (B != NULL)
        {
            sum = sum + B -> val;
            B = B -> next;
        }
        
        sum = sum + carry;
        carry = sum / 10;
        
        head -> next = new ListNode(sum % 10);
        head = head -> next;
    }
    return dummy -> next;
    
}
