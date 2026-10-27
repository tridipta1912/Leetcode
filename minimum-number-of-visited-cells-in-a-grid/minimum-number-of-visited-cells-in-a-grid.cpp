class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        using ll = int;
        ll n = grid.size();
        ll m = grid[0].size();
        vector<set<ll>> row(n);
        vector<set<ll>> col(m);
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                row[i].insert(j);
                col[j].insert(i);
            }
        }
        vector<vector<ll>> dist(n, vector<ll>(m, 1e9));
        queue<array<ll, 2>> q;
        q.push({0, 0});
        row[0].erase(0), col[0].erase(0);
        dist[0][0] = 1;
        while(!q.empty())
        {
            auto [x, y] = q.front();
            // cout << x << ' ' << y << ' ' << dist[x][y] << endl;
            q.pop(); 
            auto it = row[x].lower_bound(y);
            while(it != row[x].end())
            {
                if(*it > grid[x][y] + y) break;
                else
                {
                    ll nx = x, ny = *it;
                    it = row[x].erase(it);
                    col[ny].erase(x);
                    dist[nx][ny] = dist[x][y] + 1;
                    // it = row[x].lower_bound(y);
                    q.push({nx, ny});
                }
            }
            it = col[y].lower_bound(x);
            while(it != col[y].end())
            {
                if(*it > grid[x][y] + x) break;
                else
                {
                    ll nx = *it, ny = y;
                    it = col[y].erase(it);
                    row[nx].erase(y);
                    dist[nx][ny] = dist[x][y] + 1;
                    // it = col[y].lower_bound(x);
                    q.push({nx, ny});
                }
            }
        }
        if(dist[n - 1][m - 1] == 1e9) return -1;
        return dist[n - 1][m - 1];
    }
};