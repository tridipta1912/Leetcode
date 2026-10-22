class Solution {
public:
    int preimageSizeFZF(int k) {
        using ll = long long;
        auto find = [&](ll x)
        {
            ll r = 5;
            ll cnt = 0;
            while(x >= r)
            {
                cnt += (x / r);
                r *= 5;
            }
            return cnt;
        };

        auto f = [&](ll x)
        {
            ll L = 0, R = 1e15;
            ll ans = -1;
            while(L <= R)
            {
                ll M = L + (R - L) / 2;
                if(find(M) <= x)
                {
                    ans = M;
                    L = M + 1;
                }
                else
                {
                    R = M - 1;
                }
            }
            return ans;
        };

        return (f(k) - f(k - 1));
    }
};