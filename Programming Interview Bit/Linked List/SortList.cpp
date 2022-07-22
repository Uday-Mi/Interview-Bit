/*
Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5
**/

// METHOD 1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::sortList(ListNode* A) {
    
    struct ListNode *curr = A, *rem;
    vector <int> v;
    int cnt = 0;
    
    while (curr != NULL)
    {
        v.push_back(curr -> val);
        rem = curr;
        curr = curr -> next;
        free(rem);
        cnt++;
    }
    
    sort (v.begin(), v.end());
    
    for (int i = 0; i < cnt - 1; i++)
    {
        if (cnt == 1)
        {
            cout << v[i] << " ";
        }
        
        else
        {
            cout << v[i] << " " << "->" << " ";
        }
    }
    cout << v[cnt - 1] << " ";
    return NULL;
}

// METHOD 2


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *merge (ListNode *a, ListNode *b);

ListNode* Solution::sortList(ListNode* A) {
    
    ListNode *head = A;
    ListNode *fast = head -> next;
    ListNode *mid = head;
    
    if (A == NULL)
    return A;
    
    if (A -> next == NULL)
    return A;
    
    while (fast !=  NULL)
    {        
        fast = fast -> next;
        if (fast != NULL)
        {
            mid = mid -> next;
            fast = fast -> next;
        }
    }
    
    ListNode *a = head;
    ListNode *b = mid -> next;
    mid -> next = NULL;
    
    a = sortList(a);
    b = sortList(b);
    
    if (a == NULL)
    return b;
    
    if (b == NULL)
    return a;
    
    return merge(a, b);
    
}

ListNode *merge (ListNode *a, ListNode *b)
{
    if (a == NULL)
    return b;

    if (b == NULL)
    return a;
    
    ListNode *list;
    
    if (a -> val < b -> val)
    {
        list = a;
        a = a -> next;
    }
    
    else
    {
        list = b;
        b = b -> next;
    }
    
    ListNode *ptr = list;
    
    while (a != NULL && b != NULL)
    {
        if (a -> val <= b -> val)
        {
            list -> next = a;
            a = a-> next;
            list = list -> next;
        }
        
        else
        {
            list -> next = b;
            b = b -> next;
            list = list -> next;
        }
    }
    
    while (a != NULL)
    {
        list -> next = a;
        a = a -> next;
        list = list -> next;
    }
    
    while (b != NULL)
    {
        list -> next = b;
        b = b -> next;
        list = list -> next;
    }
    
    return ptr;
}
