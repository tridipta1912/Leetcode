class Solution {
public:
    int minXor(vector<int>& nums, int k) 
    {
        using ll = long long;
        int n = nums.size();
        const ll INF = 1e18;
        vector<vector<ll>> dp(n, vector<ll>(k + 1, INF));

        // Base case: first element as one segment
        dp[0][1] = nums[0];

        for (int i = 1; i < n; i++) {
            ll cur = 0;

            for (int j = i; j >= 0; j--) {
                cur ^= nums[j];

                if (j == 0) {
                    // Whole subarray nums[0..i] as 1 segment
                    dp[i][1] = cur;
                    continue;
                }

                for (int p = 2; p <= k; p++) {
                    // Check previous partition at j-1 with p-1 parts
                    if (dp[j - 1][p - 1] != INF) {
                        dp[i][p] = min(dp[i][p], max(dp[j - 1][p - 1], cur));
                    }
                }
            }
        }

        return (int)dp[n - 1][k];
    }
};
