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
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrder;
        TreeNode* curr = root;
        while(curr)
        {
            if(!curr->left)
            {
                inOrder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr)  prev = prev->right;
                if(!prev->right)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = nullptr;
                    inOrder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        int L = 0, R = inOrder.size() - 1;
        while(R - L >= 1)
        {
            if(inOrder[L] + inOrder[R] == k)    return true;
            if(inOrder[L] + inOrder[R] < k)     L++;
            else                    R--;
        }
        return false;
    }
};