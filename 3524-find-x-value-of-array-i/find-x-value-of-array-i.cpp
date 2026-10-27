class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        using ll = long long;
        ll n = nums.size();
        vector<vector<ll>> dp(nums.size(), vector<ll>(k, 0));
        for(ll i = 0; i < n; i++)
        {
            dp[i][nums[i] % k] = 1;
            if(i)
            {
                for(ll j = 0; j < k; j++)
                {
                    dp[i][(j * (nums[i] % k)) % k] += dp[i - 1][j];
                }
            }
        }
        for(ll i = 1; i < n; i++)
        {
            for(ll j = 0; j < k; j++)   dp[i][j] += dp[i - 1][j];
        }
        return dp.back();
    }
};