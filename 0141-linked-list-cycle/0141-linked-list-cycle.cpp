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
        map<ListNode *, int> mp;
        
        ListNode *ptr = head;
        bool flag = 0;

        while (ptr != NULL)
        {
            mp[ptr->next]++;
            if (mp[ptr->next] > 1)
            {
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        
        return flag;
    }
};