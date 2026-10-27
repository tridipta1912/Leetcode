class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));

        if(obstacleGrid[0][0] == 1 || obstacleGrid.back().back() == 1)
        {
            return 0;
        }
        dp[0][0] = 1;

        for(int i = 0; i < obstacleGrid.size(); i++)
        {
            for(int j = 0; j < obstacleGrid[0].size(); j++)
            {
                if(obstacleGrid[i][j] == 0)
                {
                    if(j > 0)   dp[i][j] += dp[i][j - 1];
                    if(i > 0)   dp[i][j] += dp[i - 1][j];
                }
            }
        }
        return dp.back().back();
    }
};