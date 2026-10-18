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
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        auto dfs = [&](this auto& self, TreeNode* cur) -> void
        {
            if(!cur || k == 0)    return;
            self(cur->left);
            k--;
            if(k == 0) 
            {
                ans = cur->val;
                return;
            }
            self(cur->right);
        };
        dfs(root);
        return ans;
    }
};