class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        using ll = long long;
        deque<array<ll, 2>> q;
        ll n = grid.size();
        ll m = grid[0].size();
        vector<vector<ll>> min_move(n, vector<ll>(m, 1e18));
        q.push_front({0, 0});
        min_move[0][0] = grid[0][0];
        
        ll dx[4] = {0, 0, 1, -1};
        ll dy[4] = {1, -1, 0, 0};
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop_front();
            for(ll i = 0; i < 4; i++)
            {
                ll nx = x + dx[i];
                ll ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || min_move[nx][ny] != 1e18)  continue;
                if(grid[nx][ny] == 0)
                {
                    q.push_front({nx, ny});
                    min_move[nx][ny] = min_move[x][y];
                }
                else
                {
                    q.push_back({nx, ny});
                    min_move[nx][ny] = min_move[x][y] + 1;
                }
            }
        }
        return min_move[n - 1][m - 1];
    }
};