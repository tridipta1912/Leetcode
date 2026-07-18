class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                pq.push({matrix[i][j], i, j});
            }
        }
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int ans = 0;
        while(!pq.empty())  
        {
            auto [val, i, j] = pq.top();
            pq.pop();
            dp[i][j] = 1;
            if(i && matrix[i - 1][j] < matrix[i][j])   dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
            if(i + 1 < n && matrix[i + 1][j] < matrix[i][j])   dp[i][j] = max(dp[i][j], dp[i + 1][j] + 1);
            if(j && matrix[i][j - 1] < matrix[i][j])   dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
            if(j + 1 < m && matrix[i][j + 1] < matrix[i][j])   dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
            ans = max(ans, dp[i][j]);
        }

        return ans;
    }
};