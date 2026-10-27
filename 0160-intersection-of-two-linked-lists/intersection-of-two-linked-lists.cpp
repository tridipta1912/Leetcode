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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        using ll = long long;
        ll distA = 0, distB = 0;
        ListNode *tmpA = headA;
        while(tmpA)    tmpA = tmpA->next, distA++;
        
        ListNode *tmpB = headB;
        while(tmpB)    tmpB = tmpB->next, distB++;

        ListNode *n1 = headA;
        ListNode *n2 = headB;

        while(distA > distB)
        {
            n1 = n1->next;
            distA--;
        }
        while(distB > distA)
        {
            n2 = n2->next;
            distB--;
        }

        while(n1 != n2)
        {
            n1 = n1->next;
            n2 = n2->next;
        }

        return n1;
    }
};