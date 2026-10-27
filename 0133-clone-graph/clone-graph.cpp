/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    map<Node*, Node*> hash;
public:
    Node* cloneGraph(Node* node) {
        if(!node)   return nullptr;
        if(hash.count(node))    return (hash[node]);

        Node* copy = new Node(node->val);
        hash[node] = copy;

        for(auto v : node->neighbors)
        {
            copy->neighbors.push_back(cloneGraph(v));
        }

        return copy;
    }
};