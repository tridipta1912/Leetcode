class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adj) {
        using ll = int;
        constexpr ll INF = 1e9;
        
        ll n = adj.size();
        ll M = (1 << n);
        
        vector<vector<vector<ll>>> dp(M, vector<vector<ll>>(n, vector<ll>(n, INF)));
        queue<array<ll, 3>> q;
        for(ll i = 0; i < n; i++)   dp[1 << i][i][i] = 0, q.push({1 << i, i, i});
        
        while(!q.empty())
        {
            auto [msk, cur, start] = q.front();
            q.pop();
            for(auto v : adj[cur])
            {
                ll nsk = msk | (1 << v);
                if(dp[nsk][v][start] == INF)
                {
                    dp[nsk][v][start] = dp[msk][cur][start] + 1;
                    q.push({nsk, v, start});
                }
            }
        }
        
        ll ans = INF;
        for(ll i = 0; i < n; i++)   
        {
            for(ll j = 0; j < n; j++) ans = min(ans, dp[M - 1][i][j]);
        }

        return ans;
    }
};