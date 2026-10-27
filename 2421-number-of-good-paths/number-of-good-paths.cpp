class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        using ll = long long;
        ll n = vals.size();
        set<ll> st(vals.begin(), vals.end());
        vector<ll> vals1(st.begin(), st.end());
        for(auto &x : vals) x = lower_bound(vals1.begin(), vals1.end(), x) - vals1.begin();
        vector<ll> par(n), sz(n, 1LL);
        iota(par.begin(), par.end(), 0LL);

        auto find = [&](this auto& self, ll x) -> ll
        {
            if(par[x] == x) return x;
            return (par[x] = self(par[x]));
        };

        auto unite = [&](ll x, ll y)
        {
            ll px = find(x);
            ll py = find(y);
            if(px == py)    return;
            if(sz[px] < sz[py]) swap(px, py);
            par[py] = px;
            sz[px] += sz[py];
        };

        vector<vector<ll>> pos(n), adj(n);
        for(ll i = 0; i < n; i++)
        {
            pos[vals[i]].push_back(i);
        }

        for(auto x : edges)
        {
            ll u = x[0], v = x[1];
            if(vals[v] <= vals[u]) adj[u].push_back(v);
            else                   adj[v].push_back(u);
        }

        ll ans = n;
        for(ll i = 0; i < n; i++)
        {
            for(auto u : pos[i])    
            {
                for(auto v : adj[u])    unite(u, v);
            }
            unordered_map<ll, ll> freq;
            for(auto x : pos[i])
            {
                ll p = find(x);
                ans += freq[p];
                freq[p]++;
            }
        }

        return ans;
    }
};