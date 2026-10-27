class Solution {
public:
    map<TreeNode*, int> maxx;
    map<TreeNode*, int> minn;
    map<TreeNode*, bool> is;
    map<TreeNode*, int> summ;
    int ans = 0;

    bool isBST(TreeNode* root)
    {
        if (!root)
            return true;

        bool b1 = isBST(root->left);
        bool b2 = isBST(root->right);

        if (!b1 || !b2)
            return false;

        if (root->left && maxx[root->left] >= root->val)
            return false;

        if (root->right && minn[root->right] <= root->val)
            return false;

        summ[root] = (root->left ? summ[root->left] : 0) +
                     (root->right ? summ[root->right] : 0) +
                     root->val;

        maxx[root] = root->right ? max(maxx[root->right], root->val) : root->val;
        minn[root] = root->left ? min(minn[root->left], root->val) : root->val;

        ans = max(ans, summ[root]);

        return true;
    }

    int maxSumBST(TreeNode* root)
    {
        isBST(root);
        return ans;
    }
};
