/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> hash;
        
        Node* cur = head;
        while(cur)  
        {
            Node* ncur = new Node(cur->val);
            hash[cur] = ncur;
            cur = cur->next;
        }

        cur = head;
        while(cur)
        {
            hash[cur]->next = hash[cur->next];
            hash[cur]->random = hash[cur->random];
            cur = cur->next;
        }

        return hash[head];
    }
};