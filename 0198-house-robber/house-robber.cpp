class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));

        if(n == 1)  return nums[0];

        dp[0][1] = nums[0];
        dp[1][1] = nums[1];

        for(int i = 2; i < n; i++)
        {
            dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 2][0], dp[i - 2][1]});
            dp[i][1] = max({dp[i - 1][0], dp[i - 2][0], dp[i - 2][1]}) + nums[i];
        }
        return max(dp[n - 2][1], dp[n - 1][1]);
    }
};