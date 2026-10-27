class Solution {
public:
#define ll long long
    const ll MOD = 1e9 + 7;
    ll BinExponentitation(ll l, ll m) {
        ll ans = 1;
        ll p = l;
        while (m > 0) {
            if (m & 1)
                ans = (ans % MOD * p % MOD) % MOD;
            p = (p % MOD * p % MOD) % MOD;
            m >>= 1;
        }
        return ans % MOD;
    }

    int countGoodNumbers(long long n) {
        ll x = n / 2;
        cout << x;
        ll a = BinExponentitation(4, x);
        ll b = BinExponentitation(5, n - x);
        int ans = (a * b) % MOD;
        return ans;
    }
};