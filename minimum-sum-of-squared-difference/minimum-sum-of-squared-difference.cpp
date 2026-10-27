class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        using ll = long long;
        vector<ll> r;
        for(ll i = 0; i < nums1.size(); i++)
        {
            r.push_back(abs(nums1[i] - nums2[i]));
        }
        ll L = 0, R = 1e9;
        ll ans = 1e18;
        while(L <= R)
        {
            ll M = L + (R - L) / 2;
            ll tot = k1 + k2;
            for(auto &x : r)
            {
                tot -= max(x - M, 0LL);
            }
            if(tot >= 0)
            {
                ll cur = 0;
                for(auto &x : r)
                {
                    ll y = min(x, M);
                    if(tot > 0 && y == M && M > 0)
                    {
                        y--;
                        tot--;
                    }
                    cur += y * y;
                }
                ans = min(ans, cur);
                R = M - 1;
            }
            else
            {
                L = M + 1;
            }
        }
        return ans;
    }
};