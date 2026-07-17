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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* ans = dummy;
        ListNode* cur = head;
        ListNode* prev = head;
        int past = 1;
        while(cur)
        {
            ListNode* ncur = cur->next;
            if(past == 1)   prev = cur;
            if(past == k)
            {
                dummy->next = cur;
                dummy = prev;
                ListNode *from = prev;
                ListNode *to = ncur;
                while(past--)
                {
                    ListNode* nfrom = from->next;
                    ListNode* nto = from;
                    from->next = to;
                    from = nfrom;
                    to = nto;
                }
                past = 0;
            }
            cur = ncur;
            past++;
        }
        return ans->next;
    }
};