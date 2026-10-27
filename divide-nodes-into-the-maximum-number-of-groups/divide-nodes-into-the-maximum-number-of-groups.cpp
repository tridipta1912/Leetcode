class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        using ll = int;
        vector<vector<ll>> adj(n);
        for(auto x : edges)
        {
            ll u = x[0], v = x[1];
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<ll> col(n, -1LL);
        bool is_Bipartite = true;
        auto dfs = [&](this auto& self, ll u) -> void
        {
            for(auto v : adj[u])
            {
                if(col[v] == -1)
                {
                    col[v] = (col[u] ^ 1LL);
                    self(v);
                }
                else if (col[v] == col[u])
                {
                    is_Bipartite = false;
                }
            }
        };

        for (int i = 0; i < n; i++) 
        {
            if (col[i] == -1) 
            {
                col[i] = 0;
                dfs(i);
            }
        }

        if (!is_Bipartite) return -1;

        if(is_Bipartite == false)   return -1;

        ll ans = 0;
        vector<ll> dist(n, -1), dist1(n, -1);
        for(ll i = 0; i < n; i++)
        {
            if(dist[i] == -1)
            {
                queue<ll> q;
                q.push(i);
                dist[i] = 1;
                vector<ll> nodes;
                while(!q.empty())
                {
                    ll u = q.front();   q.pop();
                    nodes.push_back(u);
                    for(auto v : adj[u])
                    {
                        if(dist[v] == -1)   
                        {
                            dist[v] = dist[u] + 1; 
                            q.push(v);
                        }
                    }
                }
                ll maxx = 1;
                for(auto j : nodes)
                {
                    dist1.assign(n, -1);
                    q.push(j);
                    dist1[j] = 1;
                    while(!q.empty())
                    {
                        ll u = q.front();   q.pop();
                        for(auto v : adj[u])
                        {
                            if(dist1[v] == -1)   
                            {
                                dist1[v] = dist1[u] + 1; 
                                maxx = max(maxx, dist1[v]);
                                q.push(v);
                            }
                        }
                    }
                }
                ans += maxx;
            }
        }

        return ans;
    }
};