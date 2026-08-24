class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        using ll = long long;
        constexpr ll INF = 1e18;
        ll n = nums1.size();
        ll N = (1LL << n);
        vector<ll> dp(N, INF);
        dp[0] = 0;
        for(ll i = 0; i < N; i++)
        {
            ll idx = __builtin_popcount(i);
            for(ll j = 0; j < n; j++)
            {
                if(!((i >> j) & 1)) 
                {
                    dp[i | (1LL << j)] = min(dp[i | (1LL << j)], dp[i] + (nums1[idx] ^ nums2[j]));
                }
            } 
        }
        return dp.back();
    }
};