class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(k));
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                dp[i][(nums[i] + nums[j]) % k] = max(dp[i][(nums[i] + nums[j]) % k], dp[j][(nums[i] + nums[j]) % k] + 1);
            }
            for(int j = 0; j < k; j++)  dp[i][j] = max(dp[i][j], 1), ans = max(ans, dp[i][j]);
        }
        return ans;
    }
};