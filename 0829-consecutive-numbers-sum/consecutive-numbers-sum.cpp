class Solution {
public:
    int consecutiveNumbersSum(int n) {
        using ll = long long;
        ll ans = 0;
        n *= 2;
        for(ll i = 1; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                ll A = i;
                ll B = (n / i);
                ll n = (A + B - 1);
                ll m = (B - A - 1);
                ans += (n > 0 && m >= 0 && n % 2 == 0 && m % 2 == 0);
            }
        }
        return ans;
    }
};