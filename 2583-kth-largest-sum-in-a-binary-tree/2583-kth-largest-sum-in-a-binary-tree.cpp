class Solution
{
public:
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        using ll = long long;

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            ll sz = q.size();
            ll sum = 0;

            while(sz--)
            {
                TreeNode* cur = q.front();
                q.pop();

                sum += cur->val;

                if(cur->left)  q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }

            pq.push(sum);

            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        return pq.size() == k ? pq.top() : -1;
    }
};