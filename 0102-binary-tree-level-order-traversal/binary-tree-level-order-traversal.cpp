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
    vector<vector<int>> levelOrder(TreeNode* root) {
        unordered_set<int> vis;
        vector<vector<int>> ans;
        
        function<void(TreeNode*, int)> dfs = [&](TreeNode* u, int lev)
        {
            if(!u)  return;
            if(vis.count(lev))
                ans[lev].push_back(u->val);
            else
                ans.push_back({u->val}), vis.insert(lev);
            dfs(u->left, lev + 1);
            dfs(u->right, lev + 1);
        };
        dfs(root, 0);
        return ans;
    }
};