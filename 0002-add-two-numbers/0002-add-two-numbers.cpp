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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        ListNode* dummyHead = new ListNode(0);
        ListNode* ptr = dummyHead;
        int lastDigit, temp;
        
        while (l1 != NULL && l2 != NULL)
        {
            temp = l1->val + l2->val;
            if (carry == 1)
            {
                temp++;
                carry = 0;
            }
    
            lastDigit = temp % 10;
            ptr->next = new ListNode(lastDigit);
            temp /= 10;
            
            if (temp != 0)
                carry = 1;
            
            l1 = l1->next;
            l2 = l2->next;
            ptr = ptr->next;
        }

        while (l1 != NULL)
        {
            temp = l1->val;
            if (carry == 1)
                temp++, carry = 0;

            lastDigit = temp % 10;
            ptr->next = new ListNode(lastDigit);
            temp /= 10;
            
            if (temp != 0)
                carry = 1;
            
            ptr = ptr->next;
            l1 = l1->next;
        }

        while (l2 != NULL)
        {
            int temp = l2->val;
            if (carry == 1)
                temp++, carry = 0;

            lastDigit = temp % 10;
            ptr->next = new ListNode(lastDigit);
            temp /= 10;
            
            if (temp != 0)
                carry = 1;

            ptr = ptr->next;
            l2 = l2->next;
        }
        
        if (carry == 1)
        {
            ptr->next = new ListNode(carry);
            ptr = ptr->next;
        }

        return dummyHead->next;
    }
};