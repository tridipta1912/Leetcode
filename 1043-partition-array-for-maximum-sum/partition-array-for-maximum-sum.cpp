class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, -1e9);
        dp[0] = 0;
        for(int i = 0; i < n; i++)
        {
            int maxx = 0;
            for(int j = i; j < i + k && j < n; j++)
            {
                maxx = max(maxx, arr[j]);
                dp[j + 1] = max(dp[j + 1], dp[i] + maxx * (j - i + 1));
            }
        }
        return dp.back();
    }
};