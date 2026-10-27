/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void dfs(Node *u)
    {
        if(!u)  return;

        if(!u->left) return;

        u->left->next = u->right;
        if(u->next) u->right->next = u->next->left;

        dfs(u->left);
        dfs(u->right);
    }
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
};