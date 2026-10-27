class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        using ll = int;
        vector<ll> deg(n + 1);
        vector<vector<ll>> adj(n + 1, vector<ll>(n + 1));
        for(auto x : edges)
        {
            ll u = x[0], v = x[1];
            adj[u][v] = 1, adj[v][u] = 1;
            deg[u]++;
            deg[v]++;
        }
        ll ans = 1e9;
        for(ll u = 1; u <= n; u++)
        {
            for(ll v = u + 1; v <= n; v++)
            {
                for(ll w = v + 1; w <= n; w++)
                {
                    if(adj[u][v] && adj[v][w] && adj[w][u])
                    {
                        ans = min(ans, deg[u] + deg[v] + deg[w] - 6);
                    }
                }
            }
        }

        if(ans == 1e9)  ans = -1;
        return ans;
    }
};