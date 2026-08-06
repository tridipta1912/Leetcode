class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        constexpr int dx[4] = {0, 0, 1, -1};
        constexpr int dy[4] = {1, -1, 0, 0};
        queue<array<int, 2>> q;
        
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)  dist[i][j] = 0, q.push({i, j});
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
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || dist[nx][ny] != 1e9)   continue;
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }

        return dist;
    }
};