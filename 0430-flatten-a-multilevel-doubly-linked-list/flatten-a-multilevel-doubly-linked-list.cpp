/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)   return nullptr;
        Node* cur = head;
        while(cur)
        {
            if(cur->child)
            {
                Node* ncur = cur->next;
                cur->next = flatten(cur->child);
                cur->next->prev = cur;
                cur->child = nullptr;
                while(cur->next)    
                {
                    cur = cur->next;
                }
                cur->next = ncur;
                if(ncur) ncur->prev = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};