class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        using ll = long long;
        ll m = students.size();
        ll n = students[0].size();
        vector<vector<ll>> cost(m, vector<ll>(m, 0));
        for(ll i = 0; i < m; i++)
        {
            for(ll j = 0; j < m; j++)
            {
                for(ll k = 0; k < n; k++)   cost[i][j] += (students[i][k] == mentors[j][k]);
            }
        }
        ll M = (1LL << (m));
        vector<ll> dp(M);
        for(ll msk = 0; msk < M; msk++)
        {
            ll i = __builtin_popcount(msk);
            for(ll j = 0; j < m; j++)
            {
                if(msk & (1LL << j))    continue;
                dp[msk | (1LL << j)] = max(dp[msk | (1LL << j)], dp[msk] + cost[i][j]);
            }
        }

        return dp.back();
    }
};