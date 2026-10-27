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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q, dq;
        vector<int> ans;
        if(root) 
        {
            ans.push_back(root->val);
            q.push(root);
        }
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->right) dq.push(node->right);
            if(node->left)  dq.push(node->left);
            if(q.empty())   
            {
                swap(q, dq);
                if(!q.empty())  ans.push_back(q.front()->val);
            }
        }
        return ans;
    }
};