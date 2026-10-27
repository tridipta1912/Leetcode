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
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next || k == 0) return head;
        int size = 0;
        ListNode *tmp = head;
        while(tmp)  size++, tmp = tmp->next;

        k %= size;
        if (k == 0) return head;


        tmp = head;
        k = size - k;
        for(int i = 1; i < k; i++) tmp = tmp->next;

        ListNode *ans = tmp->next;
        tmp->next = nullptr;
        tmp = ans;
        while(tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = head;
        return ans;
    }
};