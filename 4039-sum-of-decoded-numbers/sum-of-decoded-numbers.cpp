class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        using ll = long long;
        constexpr ll MOD = 1e9 + 7;
        vector<ll> width, d;
        for(auto x : nums)
        {
            width.push_back(x % 10);
            d.push_back(x / 10);
        }

        ll ans = 0;
        for(ll i = 0; i < nums.size(); i++)
        {
            ll dig = floor(log10(d[i])) + 1;
            ll rem = dig - width[i];
            ll x1 = 0, y1 = 0;
            ll cur = 1;
            for(int j = 0; j < rem; j++)
            {
                y1 += cur * (d[i] % 10);
                cur *= 10;
                d[i] /= 10;
            }
            ll res = 1;
            while(y1)
            {
                if(y1 & 1)    res *= d[i];
                d[i] *= d[i], d[i] %= MOD;
                res %= MOD;
                y1 /= 2;
            }
            ans += res, ans %= MOD;
        }
        return ans;
    }
};