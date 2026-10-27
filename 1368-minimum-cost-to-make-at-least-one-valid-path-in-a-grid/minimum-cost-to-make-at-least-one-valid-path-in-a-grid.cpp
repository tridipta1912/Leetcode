class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        constexpr int INF = 1e9;
        deque<array<int, 3>> pq;
        pq.push_back({0, 0, 0});
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INF));
        dist[0][0] = 0;
        while(!pq.empty())
        {
            auto [d, x, y] = pq.front();
            if(d < dist[x][y]) continue;
            pq.pop_front();
            if(x + 1 < n)
            {
                int nd = d + (grid[x][y] != 3);
                if(dist[x + 1][y] > nd)
                {
                    dist[x + 1][y] = nd;
                    if(nd == d) pq.push_front({nd, x + 1, y});
                    else        pq.push_back({nd, x + 1, y});
                }
            }
            if(y + 1 < m)
            {
                int nd = d + (grid[x][y] != 1);
                if(dist[x][y + 1] > nd)
                {
                    dist[x][y + 1] = nd;
                    if(nd == d) pq.push_front({nd, x, y + 1});
                    else        pq.push_back({nd, x, y + 1});
                }
            }
            if(x)
            {
                int nd = d + (grid[x][y] != 4);
                if(dist[x - 1][y] > nd)
                {
                    dist[x - 1][y] = nd;
                    if(nd == d) pq.push_front({nd, x - 1, y});
                    else        pq.push_back({nd, x - 1, y});
                }
            }
            if(y)
            {
                int nd = d + (grid[x][y] != 2);
                if(dist[x][y - 1] > nd)
                {
                    dist[x][y - 1] = nd;
                    if(nd == d) pq.push_front({nd, x, y - 1});
                    else        pq.push_back({nd, x, y - 1});
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};