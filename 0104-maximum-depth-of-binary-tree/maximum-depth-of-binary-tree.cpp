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
    int maxDepth(TreeNode* root) {
        int ans = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* u, int lev)
        {
            if(!u)  return;
            dfs(u->left, lev + 1);
            dfs(u->right, lev + 1);
            ans = max(ans, lev);
        };
        dfs(root, 1);
        return ans;
    }
};