class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;

        constexpr int dx[4] = {0, 0, 1, -1};
        constexpr int dy[4] = {1, -1, 0, 0};

        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j])
                {
                    queue<array<int, 2>> q;
                    int sum = (grid[i][j] % k);
                    q.push({i, j});
                    grid[i][j] = 0;

                    while(!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();
                        for(int i = 0; i < 4; i++)
                        {
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == 0)  continue;
                            sum += grid[nx][ny], sum %= k;
                            grid[nx][ny] = 0;
                            q.push({nx, ny});
                        }
                    }

                    ans += (sum == 0);
                }
            }
        }

        return ans;
    }
};