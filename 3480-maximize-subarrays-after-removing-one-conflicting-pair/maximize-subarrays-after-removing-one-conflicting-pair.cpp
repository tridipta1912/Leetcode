class Solution
{
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs)
    {
        using ll = long long;
        int m = conflictingPairs.size();
        vector<vector<pair<int,int>>> at(n + 2);
        for (int i = 0; i < m; ++i)
        {
            int a = conflictingPairs[i][0];
            int b = conflictingPairs[i][1];
            if (a > b) swap(a, b);
            at[a].push_back({b, i});
        }
        const int INF = n + 1;
        vector<ll> A(m), B(m);
        ll S1 = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int l = n; l >= 1; --l)
        {
            for (auto &pr : at[l])
            {
                pq.push(pr);
            }
            int b1, i1, b2;
            if (pq.empty())
            {
                b1 = INF;
                i1 = -1;
                b2 = INF;
            }
            else
            {
                auto p1 = pq.top(); pq.pop();
                b1 = p1.first;
                i1 = p1.second;
                if (pq.empty())
                {
                    b2 = INF;
                }
                else
                {
                    b2 = pq.top().first;
                }
                pq.push(p1);
            }
            ll c1 = b1 - l;
            if (c1 < 0) c1 = 0;
            ll c2 = b2 - l;
            if (c2 < 0) c2 = 0;
            S1 += c1;
            if (i1 >= 0)
            {
                A[i1] += c1;
                B[i1] += c2;
            }
        }
        ll ans = 0;
        for (int i = 0; i < m; ++i)
        {
            ans = max(ans, S1 - A[i] + B[i]);
        }
        return ans;
    }
};
