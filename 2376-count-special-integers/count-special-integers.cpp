class Solution {
public:
    int countSpecialNumbers(int n) {
        using ll = long long;
        //dp[idx][mask][tight]
        string x = to_string(n);
        n = x.length();
        constexpr ll M = (1LL << 10);
        vector<vector<array<ll, 2>>> dp(n + 1, vector<array<ll, 2>>(M, {0LL, 0LL}));
        dp[0][0][1] = 1;

        for(ll i = 0; i < n; i++)
        {
            ll dig = x[i] - '0';

            for(ll mask = 0; mask < M; mask++)
            {
                for(ll tight = 0; tight <= 1; tight++)
                {
                    if(dp[i][mask][tight] == 0)  continue;

                    ll limit = (tight ? dig : 9);

                    for(ll j = 0; j <= limit; j++)
                    {
                        if(mask == 0 && j == 0)
                        {
                            dp[i + 1][0][tight && (j == dig)] += dp[i][mask][tight];
                        }
                        else if(((mask >> j) & 1) == 0)
                        {
                            dp[i + 1][mask | (1LL << j)][tight && (j == dig)] += dp[i][mask][tight];
                        }
                    }
                }
            }
        }

        ll ans = 0;
        for(ll i = 1; i < M; i++)    ans += (dp[n][i][0] + dp[n][i][1]);
        return ans;
    }
};