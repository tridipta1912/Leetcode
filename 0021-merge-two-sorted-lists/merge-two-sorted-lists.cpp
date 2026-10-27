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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* pt = new ListNode (0);
        ListNode* result = pt;
        while(list1 != nullptr || list2 != nullptr)
        {
            if(list1 == nullptr)
            {
                ListNode* node1 = new ListNode (list2 -> val);
                result -> next = node1;
                result = result -> next;
                list2 = list2 -> next;
            }
            else if(list2 == nullptr)
            {
                ListNode* node1 = new ListNode (list1 -> val);
                result -> next = node1;
                result = result -> next;
                list1 = list1 -> next;
            }
            else if(list1 -> val <= list2 -> val)
            {
                ListNode* node1 = new ListNode (list1 -> val);
                result -> next = node1;
                result = result -> next;
                list1 = list1 -> next;
            }
            else
            {
                ListNode* node1 = new ListNode (list2 -> val);
                result -> next = node1;
                result = result -> next;
                list2 = list2 -> next;
            }
        }
        ListNode* ans = pt -> next;
        delete pt;
        return ans;
    }
};