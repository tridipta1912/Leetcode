class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        using ll = int;
        vector<vector<ll>> adj(n);
        for(auto r : edges)
        {
            ll x = r[0], y = r[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        constexpr ll LOG = 31;
        vector<array<ll, LOG>> up(n);
        vector<ll> dep(n);

        vector<ll> path(n), tin(n), tout(n);
        ll timer = 1;
        auto dfs = [&](this auto& self, ll u, ll par) -> void
        {
            tin[u] = timer++;
            path[u] ^= (1 << (s[u] - 'a'));
            for(auto &v : adj[u])
            {
                if(v != par)
                {
                    path[v] ^= path[u];
                    dep[v] = dep[u] + 1;
                    up[v][0] = u;
                    self(v, u);
                }
            }
            tout[u] = timer++;
        };
        dfs(0, -1);

        for(ll x = 1; x < LOG; x++)
        {
            for(ll i = 0; i < n; i++)   up[i][x] = up[up[i][x - 1]][x - 1];
        }

        auto get = [&](ll u, ll k)
        {
            for(ll i = LOG - 1; i >= 0; i--)
            {
                if((k >> i) & 1)    u = up[u][i];
            }
            return u;
        };

        auto lca = [&](ll u, ll v)
        {
            if(dep[v] > dep[u]) swap(u, v);

            ll diff = dep[u] - dep[v];
            u = get(u, diff);
            if(u == v)  return u;

            for(ll i = LOG - 1; i >= 0; i--)
            {
                if(up[u][i] != up[v][i])
                {
                    u = up[u][i];
                    v = up[v][i];
                }
            }

            return up[u][0];
        };

        vector<ll> B(timer + 1);

        auto update = [&](ll u, ll val)
        {
            for(ll i = u; i < timer; i += (i & (-i)))
            {
                B[i] ^= val;
            }
        };

        auto query = [&](ll u)
        {
            ll val = 0;
            for(ll i = u; i > 0; i -= (i & (-i)))
            {
                val ^= B[i];
            }
            return val;
        };

        vector<bool> ans;
        for(auto &str : queries)
        {
            stringstream ss(str);
            string type;
            ll u;
            ss >> type >> u;
            if(type[0] == 'q')
            {
               ll v;
               ss >> v;
               ll l = lca(u, v);
               ll path1 = query(tin[u]) ^ path[u];
               ll path2 = query(tin[v]) ^ path[v];
               ll val = 1 << (s[l] - 'a');
               val ^= path1, val ^= path2;
               if(__builtin_popcount(val) <= 1) ans.push_back(true);
               else                             ans.push_back(false);
            }
            else 
            {
                char ch; ss >> ch;
                ll to_add = 1 << (ch - 'a');
                ll to_remove = 1 << (s[u] - 'a');
                s[u] = ch;
                update(tin[u], (to_add ^ to_remove));
                update(tout[u], (to_add ^ to_remove));
            }
        }
        return ans;
    }
};