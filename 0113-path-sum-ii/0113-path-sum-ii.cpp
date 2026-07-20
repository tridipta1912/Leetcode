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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        if(root->left)
        {
            vector<vector<int>> arr;
            arr = (pathSum(root->left, targetSum - root->val));
            for(auto& x : arr)
            {
                x.insert(x.begin(), root->val);
                ans.push_back(x);
            }
        }
        if (root->right)
        {
            vector<vector<int>> arr;
            arr = (pathSum(root->right, targetSum - root->val));
            for(auto& x : arr)
            {
                x.insert(x.begin(), root->val);
                ans.push_back(x);
            }
        }
        if(!root->left and !root->right && root->val == targetSum)
        {
            ans.push_back({root->val});
        }
        return ans;
    }
};