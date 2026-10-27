class Solution {
public:
    int integerReplacement(int n) {
        using ll = long long;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
        unordered_map<ll, ll> dp;

        pq.push({0, n});
        dp[n] = 0;

        while (!pq.empty()) 
        {
            auto [st, val] = pq.top(); pq.pop();

            if (val == 1) return (int)st;

            if (dp[val] < st) continue;

            if (val % 2 == 0) 
            {
                ll next = val / 2;
                if (!dp.count(next) || dp[next] > st + 1) 
                {
                    dp[next] = st + 1;
                    pq.push({st + 1, next});
                }
            } 
            else 
            {
                val++;
                if (!dp.count(val) || dp[val] > st + 1) 
                {
                    dp[val] = st + 1;
                    pq.push({st + 1, val});
                }

                val -= 2;
                if (!dp.count(val) || dp[val] > st + 1) 
                {
                    dp[val] = st + 1;
                    pq.push({st + 1, val});
                }
            }
        }

        return -1; 
    }
};
