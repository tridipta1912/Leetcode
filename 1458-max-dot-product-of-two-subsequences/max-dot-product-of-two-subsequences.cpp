class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        using ll = int;
        ll n = nums1.size();
        ll m = nums2.size();
        vector<vector<ll>> dp(n, vector<ll>(m, 0));
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                dp[i][j] = nums1[i] * nums2[j];
                if(i && j)  dp[i][j] += max(dp[i - 1][j - 1], 0);
                if(i)   dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if(j)   dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};