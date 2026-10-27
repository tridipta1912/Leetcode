class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) 
    {
        using ll = long long;
        vector<vector<ll>> adj(n);
        for(auto x : edges)
        {
            ll u = x[0], v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto find = [&](ll x)
        {
            vector<ll> dist(n, 1e18);
            queue<ll> q;
            q.push(x);
            dist[x] = price[x];
            array<ll, 2> maxx = {dist[x], x};
            while(!q.empty())
            {
                ll u = q.front();
                q.pop();
                for(auto v : adj[u])
                {
                    if(dist[v] == 1e18)
                    {
                        dist[v] = dist[u] + price[v];
                        maxx = max(maxx, {dist[v], v});
                        q.push(v);
                    }
                }
            }
            return maxx;
        };

        auto [dist1, u] = find(0);
        auto [diam, v] = find(u);

        auto bfs = [&](ll x)
        {
            vector<ll> dist(n, 1e18);
            queue<ll> q;
            q.push(x);
            dist[x] = price[x];
            while(!q.empty())
            {
                ll u = q.front();
                q.pop();
                for(auto v : adj[u])
                {
                    if(dist[v] == 1e18)
                    {
                        dist[v] = dist[u] + price[v];
                        q.push(v);
                    }
                }
            }
            return dist;
        };

        vector<ll> distu = bfs(u);
        vector<ll> distv = bfs(v);
        
        ll ans = -1e18;
        for(ll i = 0; i < n; i++)   
        {
            ans = max(ans, max(distu[i], distv[i]) - price[i]);
        }
        cout << diam << endl;
        return ans;
    }
};