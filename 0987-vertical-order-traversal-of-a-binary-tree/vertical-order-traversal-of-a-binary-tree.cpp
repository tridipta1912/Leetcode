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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<array<int, 2>, vector<int>> val;
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* u, int col, int row)
        {
            if(!u)  return;
            val[{col, row}].push_back(u->val);
            dfs(u->left, col - 1, row + 1);
            dfs(u->right, col + 1,row + 1);
        };
        dfs(root, 0, 0);
        vector<vector<int>> ans;

        int prev = -(1e9);
        for(auto [a, b]: val)
        {
            vector<int> arr = b;
            sort(arr.begin(), arr.end());
            if(a[0] == prev) 
            {
                for(auto nums : arr)    ans.back().push_back(nums);
            }
            else
            {
                prev = a[0];
                ans.push_back(arr);
            }
        }
        return ans;
    }
};