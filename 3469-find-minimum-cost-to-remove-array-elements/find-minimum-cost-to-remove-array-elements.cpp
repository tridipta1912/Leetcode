class Solution {
public:
    int minCost(vector<int>& nums) {
        using ll = int;
        ll ans = 1e9;
        ll n = nums.size();
        if(n <= 2)
        {
            return *max_element(nums.begin(), nums.end());
        }
        vector<vector<ll>> dp(n, vector<ll>(n, 1e9));
        dp[2][0] = max(nums[1], nums[2]);
        dp[2][1] = max(nums[0], nums[2]);
        dp[2][2] = max(nums[0], nums[1]);
        for(ll i = 4; i < n; i += 2)
        {
            for(ll j = 0; j < i; j++)
            {
                dp[i][i] = min(dp[i][i], max(nums[j], nums[i - 1]) + dp[i - 2][j]);
                dp[i][i - 1] = min(dp[i][i - 1], max(nums[j], nums[i]) + dp[i - 2][j]);
                dp[i][j] = min(dp[i][j], max(nums[i], nums[i - 1]) + dp[i - 2][j]);
            }
        }

        if(n % 2 == 0)
        {
            ll ans = 1e9;
            for(ll i = 0; i < n; i++)   ans = min(ans, max(nums[i], nums.back()) + dp[n - 2][i]);
            return ans;
        }

            for(ll i = 0; i < n; i++)   ans = min(ans, nums[i] + dp[n - 1][i]);
            return ans;
    }
};