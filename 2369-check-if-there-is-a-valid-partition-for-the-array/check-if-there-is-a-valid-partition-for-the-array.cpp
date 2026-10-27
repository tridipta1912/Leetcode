class Solution {
public:
    bool validPartition(vector<int>& a) {
        using ll = int;
        ll n = a.size();
        map<ll, ll> dp;
        dp[0] = 1;
        for(ll i = 1; i < n; i++)
        {
            if(i >= 1 && dp[i - 1])
            {
                if(a[i] == a[i - 1])    dp[i + 1] = true;
            }
            if(i >= 2 && dp[i - 2])
            {
                if(a[i] == a[i - 1] && a[i - 1] == a[i - 2])    dp[i + 1] = true;
                if(a[i] - a[i - 1] == 1 && a[i - 1] - a[i - 2] == 1) dp[i + 1] = true;
            }
            dp.erase(i - 2);
        }
        return (dp[n] == 1);
    }
};