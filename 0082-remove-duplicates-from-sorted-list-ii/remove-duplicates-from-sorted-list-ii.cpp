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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *tmp = head;
        ListNode *dummy = new ListNode(0, nullptr);
        ListNode *ans = dummy;
        bool b = false;
        while(tmp)
        {
            if(b || (tmp->next && tmp->val == tmp->next->val))
            {
                b = true;
                if(tmp->next && tmp->val != tmp->next->val)  b = false;
                tmp = tmp->next;
            }
            else
            {
                b = false;
                ans->next = tmp;
                ans = tmp;
                tmp = tmp->next;
            }
        }
        ans->next = nullptr;
        return (dummy->next);
    }
};