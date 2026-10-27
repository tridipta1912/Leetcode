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
    bool isValidBST(TreeNode* root) {
        vector<int> sorted;
        auto dfs = [&](this auto& self, TreeNode* cur)
        {
            if(!cur)    return;
            self(cur->left);
            sorted.push_back(cur->val);
            self(cur->right);
        };
        dfs(root);
        for(int i = 1; i < sorted.size(); i++)  if(sorted[i] <= sorted[i - 1])  return false;
        return true;
    }
};