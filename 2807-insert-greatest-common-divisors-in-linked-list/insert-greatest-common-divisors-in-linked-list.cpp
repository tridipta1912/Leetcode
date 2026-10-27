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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        int prev = -1;
        ListNode *nt = head;
        ListNode *ans = head;
        while(head)
        {
            if(prev != -1)
            {
                int g = __gcd(prev, head->val);
                ListNode *cur = new ListNode(g, head);
                nt->next = cur;
            }
            prev = head->val;
            nt = head;
            head = head->next;
        }
        return ans;
    }
};