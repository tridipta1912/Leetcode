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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*, int)> dfs = [&](TreeNode* u, int lev)
        {
            if(!u) return lev;
            int l1 = dfs(u->left, lev + 1);
            int l2 = dfs(u->right, lev + 1);
            ans = max((l2 - lev) + (l1 - lev) - 2, ans);
            return max(l1, l2);
        };
        dfs(root, 0);
        return ans;
    }
};