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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode *ptr, *pp;
        pp = head;
        
        if (head == NULL)
            return head;

        while (head)
        {
            if (pp->val == val)
            {
                pp = pp->next;
                head = pp;
            }
            else
                break;
        }

        if (head == NULL)
            return head;
        
        ptr = pp->next;
        while (ptr != NULL)
        {
            if (ptr->val == val)
            {
                pp->next = ptr->next;
                ptr = pp->next;
            }
            else
            {
                pp = ptr;
                ptr = ptr->next;
            }
        }
        
        return head;
    }
};