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
    int averageOfSubtree(TreeNode* root) {
        using ll = int;
        map<TreeNode*, ll> mp, count;
        ll ans = 0;
        auto dfs = [&](this auto& self, TreeNode* cur) -> void
        {
            mp[cur] = cur->val;
            count[cur] = 1;
            if(cur->left)   
            {
                self(cur->left);
                mp[cur] += mp[cur->left];
                count[cur] += count[cur->left];
            }
            if(cur->right)   
            {
                self(cur->right);
                mp[cur] += mp[cur->right];
                count[cur] += count[cur->right];
            }
            ans += ((mp[cur] / count[cur]) == cur->val);
        };

        dfs(root);
        return ans;
    }
};