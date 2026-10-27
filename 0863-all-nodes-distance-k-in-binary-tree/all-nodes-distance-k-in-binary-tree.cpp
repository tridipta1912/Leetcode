/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> ans;
        auto find_below = [&](this auto& self, TreeNode* curr, int dist)
        {
            if(!curr)   return;
            if(dist == 0)   ans.push_back(curr->val);
            else
            {
                self(curr->left, dist - 1);
                self(curr->right, dist - 1);
            }
        };

        find_below(target, k);

        target->left = nullptr;
        target->right = nullptr;

        auto nodes_reverse = [&](this auto& self, TreeNode* curr)
        {
            if(!curr)   return false;
            if(curr == target)  return true;
            TreeNode* next = nullptr;

            if(self(curr->left))    next = curr->left, curr->left = nullptr;
            else if (self(curr->right)) next = curr->right, curr->right = nullptr;

            if(!next)   return false;

            if(!next->left)  next->left = curr;
            else if (!next->right)  next->right = curr;

            return true;
        };

        nodes_reverse(root);

        if(k) find_below(target, k);

        return ans;
    }
};