class Solution {
public:
    int minCut(string s) {
        using ll = long long;
        
        ll n = s.length();
        vector<vector<ll>> poss(n);

        for(int i = 0; i < n; i++)
        {
            ll L = i;
            ll R = i;
            while(L >= 0 && R < n && s[L] == s[R])
            {
                poss[R].push_back(L);
                L--;
                R++;
            }
            L = i;
            R = i + 1;
            while(L >= 0 && R < n && s[L] == s[R])
            {
                poss[R].push_back(L);
                L--;
                R++;
            }
        }
        vector<ll> dp(n + 1, (ll)(1e18));

        dp[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(auto v : poss[i - 1])   dp[i] = min(dp[i], dp[v] + 1);
        }

        return (int)(dp[n] - 1);
    }
};