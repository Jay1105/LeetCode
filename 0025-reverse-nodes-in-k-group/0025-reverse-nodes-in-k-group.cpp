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
    ListNode* reverse(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp;
        temp = head;
        
        for (int i = 1; i < k; i++)
        {
            if (temp == NULL || temp->next == NULL)
                return head;
            temp = temp->next;
        }
        
        if (temp != NULL)
        {
            ListNode* n = reverseKGroup(temp->next, k);
            temp->next = NULL;
            
            head = reverse(head);

            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = n;
        }

        return head;
    }
};