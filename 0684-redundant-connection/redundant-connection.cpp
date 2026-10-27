class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n + 1, 0);
        vector<int> sz(n + 1, 1);
        iota(par.begin(), par.end(), 0);

        auto find = [&](this auto& self, int x) -> int
        {
            if(par[x] == x) return x;
            return ((par[x] = self(par[x])));
        };

        auto unite = [&](int u, int v)
        {
            int ru = find(u);
            int rv = find(v);

            if(ru == rv)    return false;

            if(sz[ru] < sz[rv]) swap(ru, rv);

            sz[ru] += sz[rv];
            par[rv] = ru;

            return true;
        };

        vector<int> ans;
        for(auto x : edges)
        {
            if(!unite(x[0], x[1]))
            {
                ans = {x[0], x[1]};
            }
        }

        return ans;
    }
};