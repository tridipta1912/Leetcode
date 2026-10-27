class Solution {
public:
    int possibleStringCount(string word, int k) {
        using ll = long long;
        const ll MOD = 1e9 + 7;

        ll cnt = 1;
        vector<ll> arr;
        ll tk = 1;
        for (int i = 1; i < word.size(); ++i)
        {
            if (word[i] != word[i - 1])
            {
                tk++;
                if (cnt > 1) arr.push_back(cnt - 1);
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        if (cnt > 1) arr.push_back(cnt - 1);

        if (arr.empty()) return 1;

        k = k - tk;
        ll n = arr.size();

        ll ans = 1;
        for (auto v : arr) ans = (ans * (v + 1)) % MOD;

        if(k < 0)   return ans;
        vector<ll> dp(k + 1, 0), pref(k + 1, 0);
        dp[0] = 1;
        pref[0] = 1;
        for (int j = 1; j <= k; ++j)
        {
            pref[j] = (pref[j - 1] + dp[j]) % MOD;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j <= k; j++)
            {
                ll R = j - 1;
                ll L = max(j - arr[i], 0LL);
                dp[j] = (dp[j] + pref[R] - (L > 0 ? pref[L - 1] : 0) + MOD) % MOD;
            }
            pref[0] = dp[0];
            for (int j = 1; j <= k; ++j)
            {
                pref[j] = (pref[j - 1] + dp[j]) % MOD;
            }
        }

        ll sum = 0;
        for (int i = 0; i < k; i++) 
        {
            sum += dp[i];
            if (sum >= MOD) sum -= MOD;
        }

        return (ans - sum + MOD) % MOD;
    }
};
