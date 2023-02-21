/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *turtle, *hare;
        if (head == NULL || head->next == NULL)
            return 0;
        
        turtle = head;
        hare = head->next;
        
        while (turtle != hare)
        {
            if (turtle == NULL || hare == NULL || hare->next == NULL)
                return 0;
            turtle = turtle->next;
            hare = hare->next->next;
        }
        
        return 1;
    }
};