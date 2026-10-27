class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        // consider a tree rooted at vertex 1
        // after removing two edges -> 3 CC -> 2 out of 3 will be subtrees 
        // we will use dp to compute the xor of those subtrees 
        // dp[v] = xor of the subtree with v as the root
        // dp[v] = xor of the CC on removing [v, par[v]] edges
        // Let S be the total xor of the tree
        // S = dp[u] ^ dp[v] ^ rem => rem = S ^ dp[u] ^ dp[v]

        using ll = long long;
        ll n = nums.size();
        vector<vector<ll>> adj(n);
        for(auto nums : edges)
        {
            ll u = nums[0], v = nums[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll S = 0;
        for(auto v : nums)  S ^= v;

        vector<ll> dp(n), par(n, -1);
        
        ll ans = (ll)(1e18);
        
        function<void(ll, ll)> dfs = [&](ll u, ll pa)
        {
            dp[u] = nums[u];
            for(auto v : adj[u])
            {
                if(v != par[u])
                {
                    par[v] = u;
                    dfs(v, u);
                    dp[u] ^= dp[v];
                }
            }
        };

        dfs(0, -1);

        for(int i = 1; i < n; i++)
        {
            vector<ll> dp1(n);
            function<void(ll, ll)> dfs1 = [&](ll u, ll pa)
            {
                dp1[u] = nums[u];
                for(auto v : adj[u])
                {
                    if(v != pa)
                    {
                        dfs1(v, u);
                        dp1[u] ^= dp1[v];
                    }
                }
                ll val1 = dp[i];
                ll val2 = dp1[u];
                ll val3 = S ^ val1 ^ val2;
                if(u != par[i]) ans = min(ans, max({val1, val2, val3}) - min({val1, val2, val3}));
            };

            dfs1(par[i], i);
        }

        return ans;
    }
};