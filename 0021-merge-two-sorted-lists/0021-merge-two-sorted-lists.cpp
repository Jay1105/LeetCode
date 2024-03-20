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
        ListNode *start = NULL;
        
        if (list1 == NULL && list2 == NULL)
            return start;
        else if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;
        else
        {
            if (list1->val <= list2->val)
            {
                start = list1;
                list1 = list1->next;
            }
            else
            {
                start = list2;
                list2 = list2->next;
            }
        

            ListNode *ptr3 = start;
            while (list1 != NULL && list2 != NULL)
            {
                if (list1->val <= list2->val)
                {
                    ptr3->next = list1;
                    list1 = list1->next;
                }
                else
                {
                    ptr3->next = list2;
                    list2 = list2->next;
                }
                ptr3 = ptr3->next;
            }
            while (list1 != NULL)
            {
                ptr3->next = list1;
                ptr3 = ptr3->next;
                list1 = list1->next;
            }
            while (list2 != NULL)
            {
                ptr3->next = list2;
                ptr3 = ptr3->next;
                list2 = list2->next;
            }
            ptr3->next = NULL;
        
            return start;
        }
    }
};
