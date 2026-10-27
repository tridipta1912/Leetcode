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
    int getDecimalValue(ListNode* head) {
        ListNode *ptr = head;
        vector<int> bits;
        long long cur = 1, ans = 0;
        while(ptr)
        {
            ptr = ptr->next;
            cur *= 2;
        }
        cur /= 2;
        ptr = head;
        while(ptr)
        {
            ans += (ptr->val * cur);
            ptr = ptr->next;
            cur /= 2;
        }
        return ans;
    }
};