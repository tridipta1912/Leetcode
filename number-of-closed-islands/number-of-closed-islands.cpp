class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        using ll = int;
        ll ans = 0;
        ll n = grid.size();
        ll m = grid[0].size();
        constexpr ll dx[4] = {0, 0, 1, -1};
        constexpr ll dy[4] = {1, -1, 0, 0};

        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                {
                    bool is_boundary = false;
                    queue<array<ll, 2>> q;
                    q.push({i, j});
                    while(!q.empty())
                    {
                        auto [x, y] = q.front();
                        q.pop();
                        grid[x][y] = 1;
                        for(ll i = 0; i < 4; i++)
                        {
                            ll nx = x + dx[i];
                            ll ny = y + dy[i];
                            if(nx < 0 || ny < 0 || nx >= n || ny >= m)  is_boundary = true;
                            else if(grid[nx][ny] != 1)   q.push({nx, ny});
                        }
                    }
                    ans += (is_boundary == false);
                }
            }
        }

        return ans;
    }
};