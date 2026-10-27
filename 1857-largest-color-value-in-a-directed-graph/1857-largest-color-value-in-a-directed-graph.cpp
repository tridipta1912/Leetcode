class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        using ll = int;
        ll n = colors.length();
        vector<vector<ll>> dp(n, vector<ll>(26, 0));
        ll ans = 1;

        vector<vector<ll>> adj(n);
        vector<ll> in(n);
        
        for(auto x : edges)
        {
            ll u = x[0], v = x[1];
            adj[u].push_back(v);
            in[v]++;
        }

        queue<ll> q;
        for(ll i = 0; i < n; i++)
        {
            if(!in[i])  q.push(i), dp[i][colors[i] - 'a'] = 1;
        }

        vector<ll> topo;
        while(!q.empty())
        {
            ll u = q.front();
            q.pop();
            topo.push_back(u);
            for(auto v : adj[u])
            {
                for(int i = 0; i < 26; i++)
                {
                    dp[v][i] = max(dp[v][i], dp[u][i] + (i == colors[v] - 'a'));
                    ans = max(ans, dp[v][i]);
                }
                in[v]--;
                if(in[v] == 0)  q.push(v);
            }
        }

        if(topo.size() != n)    return -1;
        return ans;
    }
};