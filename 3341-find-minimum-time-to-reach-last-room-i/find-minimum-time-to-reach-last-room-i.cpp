class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        using ll = int;
        ll n = moveTime.size();
        ll m = moveTime[0].size();

        priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
        pq.push({0, 0, 0});

        vector<vector<ll>> dist(n, vector<ll>(m, 2e9));
        dist[0][0] = 0;

        constexpr ll dx[4] = {0, 0, 1, -1};
        constexpr ll dy[4] = {1, -1, 0, 0};
        while(!pq.empty())
        {
            auto [d, x, y] = pq.top(); pq.pop();
            if(dist[x][y] != d) continue;
            for(ll i = 0; i < 4; i++)
            {
                ll nx = x + dx[i];
                ll ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m)  continue;
                
                ll min_reach = max(moveTime[nx][ny], d) + 1;
                if(dist[nx][ny] > min_reach)
                {
                    dist[nx][ny] = min_reach;
                    pq.push({dist[nx][ny], nx, ny});
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};