class Solution {
public:
    vector<vector<vector<int>>> dp;
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        auto help = [&](int i)
        {
            if(i < 0 || i >= n)   return 1;
            return nums[i];
        };
        
        for(int len = 0; len < n; len++)
        {
            for(int i = 0; i + len < n; i++)
            {
                int j = i + len;
                for(int k = i; k <= j; k++) 
                {
                    int val = help(k) * help(i - 1) * help(j + 1);
                    if(i <= k - 1) val += dp[i][k - 1];
                    if(j >= k + 1)  val += dp[k + 1][j];
                    dp[i][j] = max(dp[i][j], val);
                }
            }
        }

        return dp[0][n - 1];
    }
};