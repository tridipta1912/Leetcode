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
    int countDominantNodes(TreeNode* root) {
        int ans = 0;
        auto find = [&](this auto& self, TreeNode* cur)
        {
            if(!cur)    return 0;
            int maxx = 0;
            maxx = max(maxx, self(cur->left));
            maxx = max(maxx, self(cur->right));
            maxx = max(maxx, cur->val);
            ans += (maxx == cur->val);
            return maxx;
        };

        find(root);
        return ans;
    }
};