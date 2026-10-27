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
    ListNode* middleNode(ListNode* head) {
        ListNode *tmp = head;
        int size = 0;
        while(tmp != nullptr)   size++, tmp = tmp->next;

        ListNode *tmp1 = head;
        for(int i = 1; i <= ((size / 2)); i++)
        {
            tmp1 = tmp1->next;
        }

        return tmp1;
    }
};