class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        using ll = long long;
        constexpr ll MOD = 1e9 + 7;
        ll n = grid.size();
        ll m = grid[0].size();
        ll M = m * n;
        
        vector<vector<ll>> adj(M);
        auto encode = [&](ll x, ll y)
        {
            return (m * x + y);
        };
        vector<ll> in(M);
        vector<ll> dx = {0, 0, 1, -1};
        vector<ll> dy = {1, -1, 0, 0};
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                for(ll k = 0; k < 4; k++)
                {
                    ll nx = i + dx[k];
                    ll ny = j + dy[k];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m)  continue;
                    if(grid[nx][ny] > grid[i][j])
                    {
                        adj[encode(i, j)].push_back(encode(nx, ny));
                        in[encode(nx, ny)]++;
                    }
                }
            }
        }

        vector<ll> dp(M, 1LL);
        queue<ll> q;
        for(ll i = 0; i < M; i++)
        {
            if(in[i] == 0)  q.push(i);
        }
        while(!q.empty())
        {
            auto u = q.front();
            q.pop();
            for(auto v : adj[u])
            {
                dp[v] += dp[u];
                dp[v] %= MOD;
                if(--in[v] == 0)    q.push(v);
            }
        }
        ll ans = 0;
        for(auto x : dp)    ans += x, ans %= MOD;
        return ans;
    }
};