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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* meet = nullptr;
        while(fast && fast->next && slow)
        {
            fast = (fast->next)->next;
            slow = slow->next;
            if(fast == slow && fast != nullptr)    
            {
                meet = fast;
                break;
            }
        }

        slow = head;
        while(meet && slow != meet)
        {
            slow = slow->next;
            meet = meet->next;
        }

        return meet;
    }
};