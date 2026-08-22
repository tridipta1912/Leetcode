class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        using ll = long long;
        vector<vector<ll>> adj(n + 1);
        vector<ll> in(n + 1);
        for(auto x : relations)
        {
            ll a = x[0], b = x[1];
            adj[b].push_back(a);
            in[a]++;
        }

        vector<ll> dp(n + 1, 0);
        
        queue<ll> q;
        for(ll i = 1; i <= n; i++)  if(!in[i])  q.push(i), dp[i] = time[i - 1];

        ll ans = *max_element(dp.begin(), dp.end());

        while(!q.empty())
        {
            ll u = q.front();
            q.pop();
            for(auto v : adj[u])
            {
                dp[v] = max(dp[v], dp[u] + time[v - 1]);
                ans = max(ans, dp[v]);
                in[v]--;
                if(!in[v])  q.push(v);
            }
        }

        return (int)ans;
    }
};