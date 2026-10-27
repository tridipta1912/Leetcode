class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        using ll = long long;
        unordered_map<ll, ll> left;   
        ll ans = 0;

        function<void(TreeNode*, ll, ll)> dfs = [&](TreeNode* node, ll depth, ll col) {
            if (!node) return;

            if (!left.count(depth))
                left[depth] = col;

            ans = max(ans, col - left[depth] + 1);

            dfs(node->left,  depth + 1, 2 * (col - left[depth]));
            dfs(node->right, depth + 1, 2 * (col - left[depth]) + 1);
        };

        dfs(root, 0, 0);  // col starts from 0
        return (int)ans;
    }
};