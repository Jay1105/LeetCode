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
        ListNode* newhead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return newhead;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (left == right)
            return head;

        ListNode *lptr, *rptr, *temp;
        temp = head;
        
        int n = 0;
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }

        if (left == 1 && right == n)
        {
            return reverse(head);
        }
        
        int m = left;
        lptr = head;
        while (left-- > 1)
            lptr = lptr->next;
        rptr = head;
        while (right-- > 1)
            rptr = rptr->next;
        
        ListNode *st = rptr->next;
        rptr->next = NULL;
        
        ListNode *ans = reverse(lptr);
        
        if (m == 1)
            head = ans;
        else
        {
            temp = head;
            while (--m > 1)
                temp = temp->next;
            temp->next = ans;
        }
        
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = st;
        
        return head;
    }
};