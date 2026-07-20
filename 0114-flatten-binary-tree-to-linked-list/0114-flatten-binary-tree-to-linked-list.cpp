/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)   return;
        TreeNode* lft = root->left;
        flatten(lft);
        TreeNode* rgt = root->right;
        root->left = nullptr;
        if(root) root->right = lft;
        TreeNode *dummy = root;
        while(dummy->right) dummy = dummy->right;
        flatten(rgt);
        if(dummy) dummy->right = rgt;
    }
};