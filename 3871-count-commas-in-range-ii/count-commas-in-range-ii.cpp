class Solution {
public:
    long long countCommas(long long n) {
        using ll = long long;
        ll ans = 0;
        ll cur = 1;
        ll tot = 1;
        while(true)
        {
            if(cur > n) break;
            ll L = cur;
            ll R = 10 * cur - 1;
            R = min(R, n);
            ans += ((tot - 1) / 3) * (R - L + 1);
            tot++;
            cur *= 10;
        }
        return ans;
    }
};