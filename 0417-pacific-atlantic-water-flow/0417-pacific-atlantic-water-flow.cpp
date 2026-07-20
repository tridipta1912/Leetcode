class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {1, -1, 0, 0};
        int n = heights.size();
        int m = heights[0].size();
        queue<array<int, 2>> p, q;
        vector<vector<int>> visp(n, vector<int>(m, 0));
        vector<vector<int>> visa(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++)  visp[0][i] = 1, visa[n - 1][i] = 1, p.push({0, i}), q.push({n - 1, i});
        for(int i = 0; i < n; i++)  visp[i][0] = 1, visa[i][m - 1] = 1, p.push({i, 0}), q.push({i, m - 1});

        while(!p.empty())
        {
            auto [x, y] = p.front();
            p.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || visp[nx][ny])  continue;
                else if (heights[nx][ny] >= heights[x][y])  
                {
                    visp[nx][ny] = true;
                    p.push({nx, ny});
                }
            }
        }
    
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || visa[nx][ny])  continue;
                else if (heights[nx][ny] >= heights[x][y])  
                {
                    visa[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(visp[i][j] && visa[i][j])    ans.push_back({i, j});
            }
        }

        return ans;
    }
};