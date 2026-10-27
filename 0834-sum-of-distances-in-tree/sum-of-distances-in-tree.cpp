class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        using ll = int;
        vector<ll> dp(n), dp1(n), sub(n, 1LL);
        vector<vector<ll>> adj(n);

        for(auto x : edges)
        {
            ll u = x[0], v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto dfs = [&](this auto& self, ll u, ll par) -> void
        {
            for(auto v : adj[u])
            {
                if(v != par)
                {
                    self(v, u);
                    dp[u] += (dp[v] + sub[v]);
                    sub[u] += sub[v];
                }
            }
        };

        dfs(0, -1);

        vector<int> ans;
        dp1[0] = dp[0];
        auto dfs1 = [&](this auto& self, ll u, ll par) -> void
        {
            for(auto v : adj[u])
            {
                if(v != par)
                {
                    dp1[v] = dp1[u] + (n - 2 * sub[v]);
                    self(v, u);
                }
            }
        };

        dfs1(0, -1);
        return dp1;
    }
};