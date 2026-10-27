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
    bool isBalanced(TreeNode* root) {
        bool b = true;
        function<int(TreeNode*, int)> dfs = [&](TreeNode* u, int lev)
        {
            if(!u)  return lev;
            int l1 = dfs(u->left, lev + 1);
            int l2 = dfs(u->right, lev + 1);
            if(abs(l2 - l1) > 1)    b = false;
            return max(l1, l2);
        };
        dfs(root, 0);
        return b;
    }
};