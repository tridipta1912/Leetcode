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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int depth = 0;
        map<int, vector<int>> nodes;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* cur, int depth)
        {
            if(!cur)    return;
            nodes[depth].push_back(cur->val);
            dfs(cur->left, depth + 1);
            dfs(cur->right, depth + 1);
        };
        dfs(root, 0);
        vector<vector<int>> ans;
        for(auto [x, y] : nodes)
        {
            if(x % 2)   reverse(y.begin(), y.end());
            ans.push_back(y);
        }
        return ans;
    }
};