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
        ll M = (1LL << (2 * m));
        vector<ll> dp(M);
        for(ll msk = 0; msk < M; msk++)
        {
            for(ll i = 0; i < m; i++)
            {
                for(ll j = 0; j < m; j++)
                {
                    ll bitt = (1LL << m) * (1LL << i);
                    bitt |= (1LL << j);
                    if((msk & bitt) == 0)   
                    {
                        dp[msk | bitt] = max(dp[msk | bitt], dp[msk] + cost[i][j]);
                    }
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};