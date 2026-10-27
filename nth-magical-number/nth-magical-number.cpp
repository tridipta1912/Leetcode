class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        using ll = long long;
        ll lcm = a * (b / __gcd(a, b));
        ll L = 1, R = 1e18;
        ll ans = -1;
        while(L <= R)
        {
            ll M = L + (R - L) / 2;
            ll cnt = ((M / a) + (M / b) - (M / lcm));
            if(cnt >= n)
            {
                ans = M;
                R = M - 1;
            }
            else
            {
                L = M + 1;
            }
        }
        return (ans % static_cast<int>(1e9 + 7));
    }
};