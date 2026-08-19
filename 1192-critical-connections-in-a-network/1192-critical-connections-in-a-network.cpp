class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        using ll = long long;
        const ll INF = 1e18;
        vector<ll> tin(n), vis(n), low(n, INF);
        ll timer = 0;
        vector<vector<ll>> adj(n);
        vector<vector<int>> ans;
        for(auto x : connections)
        {
            ll u = x[0], v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto dfs = [&](this auto& self, ll u, ll par) -> void
        {
            tin[u] = timer++;
            low[u] = tin[u];
            vis[u] = true;
            for(auto v : adj[u])
            {
                if(v != par)
                {
                    if(vis[v])  
                    {
                        low[u] = min(low[u], tin[v]);
                    }
                    else
                    {
                        self(v, u);
                        low[u] = min(low[v], low[u]);
                    }
                }
            }
            if(u && low[u] > tin[par])   
            {
                ans.emplace_back();
                ans.back() = {(int)u, (int)par};
            }
        };

        dfs(0, -1);

        return ans;
    }
};