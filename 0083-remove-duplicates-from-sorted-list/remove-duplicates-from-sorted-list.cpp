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
        ListNode *cur = head;
        while(cur != nullptr && cur->next != nullptr)
        {
            ListNode *nxt = cur->next;
            while(nxt != nullptr && nxt->val == cur->val)
            {
                ListNode *rem = nxt;
                nxt = nxt->next;
                //delete rem;
            }
            cur->next = nxt;
            cur = nxt;
        }
        return head;
    }
};