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
    ListNode* swapPairs(ListNode* head) {
        ListNode *tmp = head;
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        
        while(tmp != nullptr && tmp->next != nullptr)
        {
            ListNode *nxt = tmp->next;
            prev->next = nxt;
            tmp->next = nxt->next;
            nxt->next = tmp;

            prev = tmp;
            tmp = tmp->next;
        }
        return dummy->next;
    }
};