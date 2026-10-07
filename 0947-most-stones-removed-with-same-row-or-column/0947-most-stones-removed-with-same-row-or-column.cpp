using ll = long long;
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        ll n = stones.size();
        vector<ll> par(n), sz(n, 1LL);
        iota(par.begin(), par.end(), 0);
        auto find = [&](this auto& self, ll x)
        {
            if(par[x] == x) return x;
            return (par[x] = self(par[x]));
        };
        auto unite = [&](ll x, ll y)
        {
            ll px = find(x);
            ll py = find(y);
            if(px == py)    return false;
            
            if(sz[py] > sz[px]) swap(px, py);

            sz[px] += sz[py];
            par[py] = px;
            return true;
        };

        ll ans = 0;
        for(ll i = 0; i < n; i++)
        {
            for(ll j = i + 1; j < n; j++)
            {
                if((stones[i][0] == stones[j][0]) || (stones[i][1] == stones[j][1]))    
                {
                    if(unite(i, j)) ans++;
                }
            }
        }
        return ans;
    }
};