class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        long long answer = 0;
        vector<long long> dp(4);

        dp[0] = static_cast<long long>(a[0]) * b[0];
        dp[1] = dp[0] + static_cast<long long>(a[1]) * b[1];
        dp[2] = dp[1] + static_cast<long long>(a[2]) * b[2];
        dp[3] = dp[2] + static_cast<long long>(a[3]) * b[3];

        for (int i = 1; i < b.size(); i++) {
            if (i > 3) dp[3] = max(dp[2] + static_cast<long long>(a[3]) * b[i], dp[3]);
            if (i > 2) dp[2] = max(dp[1] + static_cast<long long>(a[2]) * b[i], dp[2]);
            if (i > 1) dp[1] = max(dp[0] + static_cast<long long>(a[1]) * b[i], dp[1]);
            long long x = static_cast<long long>(a[0]) * b[i];
            if (i > 0) dp[0] = max(dp[0], x);
        }
        return dp[3];
    }
};
