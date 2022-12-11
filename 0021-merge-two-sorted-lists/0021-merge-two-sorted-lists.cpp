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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ptr1, *ptr2;
        ptr1 = list1, ptr2 = list2;
        ListNode *start = NULL;
        
        if (ptr1 == NULL && ptr2 == NULL)
            return start;
        else if (ptr1 == NULL)
            return list2;
        else if (ptr2 == NULL)
            return list1;
        else
        {
            if (ptr1->val <= ptr2->val)
            {
                start = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                start = ptr2;
                ptr2 = ptr2->next;
            }
        

            ListNode *ptr3 = start;
            while (ptr1 != NULL && ptr2 != NULL)
            {
                if (ptr1->val <= ptr2->val)
                {
                    ptr3->next = ptr1;
                    ptr1 = ptr1->next;
                }
                else
                {
                    ptr3->next = ptr2;
                    ptr2 = ptr2->next;
                }
                ptr3 = ptr3->next;
            }
            while (ptr1 != NULL)
            {
                ptr3->next = ptr1;
                ptr3 = ptr3->next;
                ptr1 = ptr1->next;
            }
            while (ptr2 != NULL)
            {
                ptr3->next = ptr2;
                ptr3 = ptr3->next;
                ptr2 = ptr2->next;
            }
            ptr3->next = NULL;
        
            return start;
        }
    }
};