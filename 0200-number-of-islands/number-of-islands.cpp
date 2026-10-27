class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
    
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {1, -1, 0, 0};

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    queue<array<int, 2>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    ans++;
                    while(!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();
                        for(int i = 0; i < 4; i++)
                        {
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == '0')   continue;
                            grid[nx][ny] = '0';
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }

        return ans;
    }
};