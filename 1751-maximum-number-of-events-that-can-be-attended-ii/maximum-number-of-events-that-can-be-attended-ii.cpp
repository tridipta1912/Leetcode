class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1];
        });

        using ll = int;

        ll n = events.size();
        vector<vector<ll>> dp(n, vector<ll>(k + 1, -(1e9)));
        
        dp[0][0] = 0;
        dp[0][1] = events[0][2];
        for(int i = 1; i < n; i++)
        {
            ll L = 0, R = i - 1;
            ll idx = -1;
            while(L <= R)
            {
                ll M = L + (R - L) / 2;
                if(events[M][1] < events[i][0])
                {
                    idx = M;
                    L = M + 1;
                }
                else
                {
                    R = M - 1;
                }
            }
            for(int j = 0; j <= k; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if(j > 0)   dp[i][j] = max({dp[i][j], dp[i][j - 1], (idx != -1 ? dp[idx][j - 1] : 0) + events[i][2]});
            }
        }

        return (int)(dp[n - 1][k]);
    }
};