/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        
        if (len < 2)
            return head;
        k %= len;
        if (k == 0)
            return head;
        
        int tp = len - k;
        
        temp = head;
        ListNode* newHead;
        while (--tp)
            temp = temp->next;
        newHead = temp->next;
        temp->next = NULL;
        
        temp = newHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head;
        
        return newHead;
    }
};