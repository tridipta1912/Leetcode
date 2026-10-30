class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        using ll = int;
        vector<vector<array<ll, 2>>> adj(n);
        for(auto x : edges)
        {
            ll u = x[0], v = x[1], w = x[2];
            adj[u].push_back({v, w});
        }

        vector<vector<ll>> dist(n, vector<ll>(k + 1, 1e9));
        priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
        pq.push({0, 0, 1});
        dist[0][1] = 0;

        while(!pq.empty())
        {
            auto [d, u, r] = pq.top();
            pq.pop();
            if(dist[u][r] != d) continue;
            for(auto [v, w] : adj[u])
            {
                if(labels[u] == labels[v] && r + 1 <= k)
                {
                    if(dist[v][r + 1] > dist[u][r] + w)
                    {
                        dist[v][r + 1] = dist[u][r] + w;
                        pq.push({dist[v][r + 1], v, r + 1});
                    }
                }
                else if(labels[u] != labels[v])
                {
                    if(dist[v][1] > dist[u][r] + w)
                    {
                        dist[v][1] = dist[u][r] + w;
                        pq.push({dist[v][1], v, 1});
                    }
                }
            }
        }

        ll ans = 1e9;
        for(ll i = 1; i <= k; i++)  ans = min(ans, dist[n - 1][i]);

        return ((ans == 1e9) ? -1 : ans);
    }
};