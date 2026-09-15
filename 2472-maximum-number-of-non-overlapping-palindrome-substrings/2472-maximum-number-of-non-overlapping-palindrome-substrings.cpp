class Solution {
public:
    int maxPalindromes(string s, int k) {
        using ll = long long;
        ll n = s.length();
        vector<vector<ll>> dp(n, vector<ll>(n, 0));
        vector<array<ll, 2>> intervals;
        for(ll len = 1; len <= n; len++)
        {
            for(ll i = 0; i + len - 1 < n; i++)
            {
                ll j = i + len - 1;
                if(len == 1)    dp[i][j] = 1;
                else if(s[i] == s[j])
                {
                    if(len == 2)    dp[i][j] = 1;
                    else if (dp[i + 1][j - 1])
                    {
                        dp[i][j] = 1;
                    }
                }
                if(len >= k && dp[i][j])    intervals.push_back({i, j});
            }
        }
        sort(intervals.begin(), intervals.end(), [&](auto &a, auto &b)
        {
            return (a[1] < b[1]);
        });
        ll cnt = 0, maxx = -1;
        for(auto [x, y] : intervals)
        {
            if(maxx < x)
            {
                cnt++;
                maxx = y;
            }
        }
        return cnt;
    }
};