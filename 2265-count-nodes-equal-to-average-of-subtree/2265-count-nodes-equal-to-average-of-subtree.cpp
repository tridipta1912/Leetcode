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
        ll ans = 0;
        auto dfs = [&](this auto& self, TreeNode* cur) -> array<ll, 2>
        {
            array<ll, 2> v = {0, 0};
            v[0] = cur->val;
            v[1] = 1;
            if(cur->left)   
            {
                auto [value, count] = self(cur->left);
                v[0] += value;
                v[1] += count;
            }
            if(cur->right)   
            {
                auto [value, count] = self(cur->right);
                v[0] += value;
                v[1] += count;
            }
            ans += ((v[0] / v[1]) == cur->val);
            return v;
        };

        dfs(root);
        return ans;
    }
};