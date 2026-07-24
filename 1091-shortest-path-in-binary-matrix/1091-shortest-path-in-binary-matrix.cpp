class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> dx = {0, 0, 1, -1, 1, -1, 1, -1};
        vector<int> dy = {1, -1, 0, 0, 1, -1, -1, 1};

        if(grid[0][0])  return -1;

        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 1e9));
        
        queue<array<int, 2>> q;
        q.push({0, 0});
        dp[0][0] = 1;

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 8; i++)  
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] || dp[nx][ny] != 1e9)     continue;
                dp[nx][ny] = dp[x][y] + 1;
                q.push({nx, ny});
            }
        }

        if(dp.back().back() == 1e9) return -1;
        return dp.back().back();
    }
};