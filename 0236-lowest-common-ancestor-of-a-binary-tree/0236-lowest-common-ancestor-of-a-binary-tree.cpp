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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        
        unordered_map<TreeNode*, bool> isp;
        
        auto isP = [&](this auto& self, TreeNode* node)
        {
            if(!node)   return false;
            if(node == p)   
            {
                isp[node] = true; 
            }
            isp[node] |= self(node->left);
            isp[node] |= self(node->right);
            return isp[node];
        };

        auto isQ = [&](this auto& self, TreeNode* node)
        {
            if(!node)   return false;
            if(node == q) 
            {
                if(isp[node]) ans = node;
                return true;
            }
            if (self(node->left) || self(node->right))
            {
                if(isp[node] && ans == root) ans = node;
                return true;
            }
            return false;
        };

        isP(root);
        isQ(root);
        return ans;
    }
};