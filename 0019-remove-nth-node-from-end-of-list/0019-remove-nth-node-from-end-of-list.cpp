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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;
    
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
    
        if (len == n)
        {
            head = head->next;
            return head;
        }
        
        int ele = len - n;
        temp = head;

        while (--ele)
            temp = temp->next;
        temp->next = temp->next->next;
        
        return head;
    }
};