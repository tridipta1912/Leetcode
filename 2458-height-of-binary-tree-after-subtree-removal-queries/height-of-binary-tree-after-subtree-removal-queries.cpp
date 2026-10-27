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
using ll = int;        
struct Segtree
{
    vector<ll> T;
    Segtree(vector<ll> &arr)
    {
        ll n = arr.size();
        T.assign(4 * n, 0);
        build(1, 0, n - 1, arr);
    }
    void build(ll v, ll l, ll r, vector<ll> &arr)
    {
        if(l == r)
        {
            T[v] = arr[l];
            return;
        }
        ll m = (l + r) / 2;
        build(2 * v, l, m, arr);
        build(2 * v + 1, m + 1, r, arr);
        T[v] = max(T[2 * v], T[2 * v + 1]);
    }
    ll query(ll v, ll l, ll r, ll ql, ll qr)
    {
        if(l >= ql && r <= qr)  return T[v];
        if(r < ql || l > qr)    return 0;
        ll m = (l + r) / 2;
        return max(query(2 * v, l, m, ql, qr), query(2 * v + 1, m + 1, r, ql, qr));
    }
};
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<ll, ll> tin, tout;
        unordered_map<ll, ll> dp;
        ll timer = 0;
        auto dfs = [&](this auto& self, TreeNode* u) -> int
        {
            tin[u->val] = timer++;
            if(u->left) dp[u->left->val] = dp[u->val] + 1, self(u->left);
            if(u->right)    dp[u->right->val] = dp[u->val] + 1, self(u->right);
            tout[u->val] = timer++;
            return dp[u->val];
        };
        dfs(root);
        vector<ll> euler(timer);
        for(auto [x, y] : tin)  euler[y] = dp[x];
        for(auto [x, y] : tout) euler[y] = dp[x];

        Segtree st(euler);
        vector<ll> answer;

        for(auto x : queries)
        {
            ll ans = 0;
            if(tin[x])  ans = max(ans, st.query(1, 0, timer - 1, 0, tin[x] - 1));
            if(tout[x] + 1 < timer)  ans = max(ans, st.query(1, 0, timer - 1, tout[x] + 1, timer - 1));
            answer.push_back(ans);
        }

        return answer;
    }
};