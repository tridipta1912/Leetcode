class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<vector<int>> dp = triangle;

        for(int ind = 0; ind < triangle.size() - 1; ind++)
        {
            for(int i = 0; i <= triangle[ind].size(); i++)   dp[ind + 1][i] = 1e9;
            for(int i = 0; i < triangle[ind].size(); i++)
            {
                dp[ind + 1][i] = min(triangle[ind + 1][i] + dp[ind][i], dp[ind + 1][i]);
                dp[ind + 1][i + 1] = min(triangle[ind + 1][i + 1] + dp[ind][i], dp[ind + 1][i + 1]);
            }
        }

        int ans = 1e9;
        for(auto nums: dp.back()) ans = min(nums, ans);

        return ans;
    }
};