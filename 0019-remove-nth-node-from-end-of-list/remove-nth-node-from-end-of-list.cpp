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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode *tmp = head;
        while(tmp != nullptr)   tmp = tmp->next, size++;
        ListNode *tmp1 = head;
        if(n == size)   
        {
            tmp1 = tmp1->next;
            delete head;
            return tmp1;
        }
        for(int i = 1; i <= (size - n - 1); i++)
        {
            tmp1 = tmp1->next;
        }
        ListNode *tmp2 = tmp1;
        tmp2 = tmp2->next;
        tmp1->next = tmp2->next;
        delete tmp2;
        return head;
    }
};