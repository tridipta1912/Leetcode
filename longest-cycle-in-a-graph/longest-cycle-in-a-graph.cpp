class Solution {
public:
    int longestCycle(vector<int>& edges) {
        using ll = long long;
        ll n = edges.size();
        vector<ll> F(n, -1);
        for(ll i = 0; i < n; i++)
        {
            if(edges[i] != -1)  F[i] = edges[i];
        }
        ll ans = -1e18;
        vector<ll> dist(n, -1);
        vector<ll> seen(n, 0LL);
        for(ll i = 0; i < n; i++)
        {
            if(seen[i] == 0)
            {
                ll cur = i;

                vector<ll> vis;
                vis.push_back(cur);
                dist[cur] = 0;

                while(F[cur] != -1)
                {
                    ll ncur = F[cur];
                    if(seen[ncur]) break;
                    else if(dist[ncur] != -1)
                    {
                        ans = max(ans, dist[cur] - dist[ncur] + 1);
                        break;
                    }
                    else
                    {
                        dist[ncur] = dist[cur] + 1;
                        cur = ncur;
                        vis.push_back(cur);
                    }
                }

                for(auto x : vis)   seen[x] = true;
            }
        }
        if(ans == -1e18)    return -1;
        return ans;
    }
};