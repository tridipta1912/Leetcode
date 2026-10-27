class Solution {
public:
    int countOrders(int n) {
        using ll = long long;
        constexpr int MOD = 1e9 + 7;
        ll ans = 1;
        for(int i = 1; i < n; i++)
        {
            ans *= ((i + 1) * (2 * i + 1));
            ans %= MOD;
        }
        return static_cast<int>(ans);
    }
};