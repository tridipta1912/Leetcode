class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        using ll = int;
        ll M = *max_element(nums.begin(), nums.end());
        vector<ll> spf(M + 1, -1), ord(M + 1, 0);
        ll cur = 0;
        for(ll i = 2; i <= M; i++)
        {
            if(spf[i] == -1)
            {
                ord[i] = cur++;
                for(ll j = i; j <= M; j += i)
                {
                    spf[j] = i;        
                }
            }
        }

        vector<ll> par(M + 1), sz(M + 1, 1);
        iota(par.begin(), par.end(), 0);

        auto find = [&](this auto& self, ll x) -> ll
        {
            if(par[x] == x) return x;
            return (par[x] = self(par[x]));
        };

        auto unite = [&](ll x, ll y)
        {
            ll px = find(x);
            ll py = find(y);
            if(px == py)    return false;
            if(sz[px] < sz[py]) swap(px, py);

            sz[px] += sz[py];
            par[py] = px;
            return true;
        };

        for(ll i = 0; i < nums.size(); i++)
        {
            ll x = nums[i];
            vector<ll> prime;
            while(x > 1)
            {
                ll r = spf[x];
                while(x % r == 0)
                {
                    x /= r;
                }
                prime.push_back(r);
            }
            for(ll j = 1; j < prime.size(); j++)    
            {
                unite(ord[prime[j]], ord[prime[j - 1]]);
            }
        }

        unordered_map<ll, vector<ll>> can_sort, idx;
        for(ll i = 0; i < nums.size(); i++)
        {
            ll r = find(ord[(spf[nums[i]])]);
            can_sort[r].push_back(nums[i]);
            idx[r].push_back(i);
        }

        for(auto &[x, y] : can_sort)
        {
            sort(y.begin(), y.end());
            sort(idx[x].begin(), idx[x].end());
            for(ll i = 0; i < y.size(); i++)    nums[idx[x][i]] = y[i];
        }

        for(ll i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i - 1])   return false;
        }

        return true;
    }
};