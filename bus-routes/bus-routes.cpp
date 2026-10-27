class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        using ll = int;
        unordered_map<ll, ll> vis;
        unordered_map<ll, ll> dist;
        ll n = routes.size();
        unordered_map<ll, vector<ll>> pos;
        for(ll i = 0; i < n; i++)
        {
            for(auto x : routes[i]) pos[x].push_back(i);
        }
        dist[source] = 0;
        queue<ll> q;
        q.push(source);
        while(!q.empty())
        {
            ll u = q.front();
            q.pop();
            for(auto v : pos[u])
            {
                if(vis.find(v) == vis.end())
                {
                    vis[v] = 1;
                    for(auto x : routes[v])
                    {
                        if(dist.find(x) == dist.end())
                        {
                            dist[x] = dist[u] + 1;
                            q.push(x);
                        }
                    }
                }
            }
        }

        if(dist.find(target) == dist.end()) return -1;
        
        return dist[target];
    }
};