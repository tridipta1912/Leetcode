class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {1, -1, 0, 0};

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    queue<array<int, 2>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    ans++;
                    while(!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();
                        for(int i = 0; i < 4; i++)
                        {
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            if(nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || grid[nx][ny] == '0')   continue;
                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }

        return ans;
    }
};