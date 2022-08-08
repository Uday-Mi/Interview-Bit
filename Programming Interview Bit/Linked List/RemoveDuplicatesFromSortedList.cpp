/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,

Given 1->1->2, return 1->2.

Given 1->1->2->3->3, return 1->2->3.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    vector <int> v; 
    
    v.push_back(A -> val);
    int i = 0;
    
    A = A -> next;
    
    while (A != NULL)
    {
        int a = A -> val;
        if (a != v[i])
        {
            v.push_back(a);
            i++;
        }
        A = A -> next;
    }
    
    int n = v.size();
    
    for (int i = 0; i < n - 1; i++)
    {
        cout << v[i] << " -> ";
    }
    
    cout << v[n - 1] << " ";
    
    return NULL;
    
}
