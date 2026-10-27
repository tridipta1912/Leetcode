class Solution {
public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        using ll = long long;
        ll n = edges.size() + 1;
        vector<vector<array<ll, 2>>> adj(n);
        for(auto x : edges)
        {
            ll u = x[0], v = x[1], w = x[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<array<ll, 2>> dp(n);
        auto dfs = [&](this auto& self, ll u, ll par) -> void
        {
            vector<ll> take;
            ll sum = 0;
            for(auto [v, w] : adj[u])
            {
                if(v != par)
                {
                    self(v, u);
                    sum += dp[v][0];
                    take.push_back(dp[v][1] + w - dp[v][0]);
                }
            }
            ll sum1 = 0, sum2 = 0;
            sort(take.begin(), take.end(), greater<ll>());
            for(ll i = 0; i < take.size(); i++)
            {
                if(i < k)   sum1 += max(take[i], 0LL);
                if(i + 1 < k)   sum2 += max(take[i], 0LL);
            }
            dp[u] = {sum1 + sum, sum2 + sum};
        };

        dfs(0, -1);

        return max(dp[0][0], dp[0][1]);
    }
};