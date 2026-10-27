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
    TreeNode* merge(vector<int> &arr, int l, int r)
    {
        int m = l + (r - l) / 2;
        if(l < 0 || r >= arr.size() || m < l || m > r)    return nullptr;
        TreeNode* node = new TreeNode(arr[m]);
        node->left = merge(arr, l, m - 1);
        node->right = merge(arr, m + 1, r);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        TreeNode* node = merge(nums, 0, nums.size() - 1);
        return node;
    }
};