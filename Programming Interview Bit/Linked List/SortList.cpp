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
