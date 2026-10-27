class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        using ll = long long;
        vector<vector<array<ll, 2>>> adj(n);
        for(auto x : edges)
        {
            ll u = x[0], v = x[1], w = x[2];
            adj[v].push_back({u, w});
            adj[u].push_back({v, w});
        }
        
        vector<ll> dist(n, 1e18);
        priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
        pq.push({0, 0});
        dist[0] = 0;

        ll ans = 0;
        while(!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if(dist[u] != d || d > maxMoves)    continue;
            ans++;
            for(auto [v, w] : adj[u])
            {
                ans += min(w, maxMoves - d);
                if(dist[v] > dist[u] + w + 1)  
                {
                    dist[v] = dist[u] + w + 1;
                    pq.push({dist[v], v});
                }
            }
        }

        for(auto x : edges)
        {
            ll u = x[0], v = x[1], w = x[2];
            ll cntu = min(w, maxMoves - dist[u]);
            ll cntv = min(w, maxMoves - dist[v]);
            ll R = cntu;
            ll L = w - cntv + 1;
            ans -= max(R - L + 1, 0LL);
        }
        return ans;
    }
};