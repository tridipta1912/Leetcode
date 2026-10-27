class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        using ll = int;
        ll n = grid.size(), m = grid[0].size();
        ll M = n * m;
        
        vector<ll> par(M), sz(M, 0);
        iota(par.begin(), par.end(), 0);
        auto find = [&](this auto& self, ll x) -> ll
        {
            if(par[x] == x) return x;
            return (par[x] = self(par[x]));
        };
        auto unite = [&](ll x, ll y)
        {
            ll px = find(x), py = find(y);
            if(px == py)    return false;
            if(sz[px] < sz[py]) swap(px, py);
            sz[px] += sz[py];
            par[py] = px;
            return true;
        };

        auto enc = [&](ll x, ll y) {return (m * x + y);};

        unordered_map<ll, vector<array<ll, 2>>> pos;
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                pos[grid[i][j]].push_back({i, j});
            }
        }

        vector<ll> vis(M);
        ll cur = 0;
        vector<array<ll, 2>> que;
        for(ll i = 0; i < queries.size(); i++)  que.push_back({queries[i], i});
        sort(que.begin(), que.end());
        vector<ll> ans(queries.size());

        ll dx[4] = {0, 0, 1, -1};
        ll dy[4] = {1, -1, 0, 0};
        
        for(auto [val, idx] : que)
        {
            while(cur < val)
            {
                if(pos.count(cur))
                {
                    while(!pos[cur].empty())
                    {
                        auto [x, y] = pos[cur].back();
                        pos[cur].pop_back();
                        sz[enc(x, y)] = 1;
                        for(ll i = 0; i < 4; i++)
                        {
                            ll nx = x + dx[i];
                            ll ny = y + dy[i];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m || !vis[enc(nx, ny)])  continue;
                            unite(enc(x, y), enc(nx, ny));
                        }
                        vis[enc(x, y)] = 1;
                    }
                }
                cur++;
            }
            ans[idx] = sz[find(0)];
        }
        return ans;
    }
};