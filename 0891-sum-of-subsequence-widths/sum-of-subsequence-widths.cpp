class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        using ll = long long;
        constexpr ll MOD = 1e9 + 7;
        
        ll n = nums.size();
        vector<ll> pow2(n, 1);
        for(ll i = 1; i < n; i++)   pow2[i] = (2 * pow2[i - 1]) % MOD;

        auto find = [&](vector<int> &a)
        {
            ll ans = 0;
            for(ll i = 0; i < n; i++)   ans += (a[i] * pow2[n - i - 1]), ans %= MOD;
            return ans;
        };

        ll maxx, minn;
        sort(nums.begin(), nums.end());
        minn = find(nums);
        reverse(nums.begin(), nums.end());
        maxx = find(nums);
        return (static_cast<int>(((maxx - minn) % MOD + MOD) % MOD));
    }
};