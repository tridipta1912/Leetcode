class Solution {
public:
    bool winnerSquareGame(int n) {
        using ll = int;
        vector<ll> dp(n + 1);
        dp[1] = 1;
        for(ll i = 2; i <= n; i++)
        {
            ll cur = 1;
            while(i - (cur * cur) >= 0)   
            {
                if(dp[i - (cur * cur)] == 0)   dp[i] = 1;
                cur++;
            }
        }
        return dp[n];
    }
};