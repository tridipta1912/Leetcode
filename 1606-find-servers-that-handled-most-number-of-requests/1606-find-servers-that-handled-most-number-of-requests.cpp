class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        using ll = int;
        vector<ll> B(k + 1);
        auto update = [&](ll x, ll val)
        {
            for(ll i = x; i <= k; i += (i & (-i)))
            {
                B[i] += val;
            }
        };
        auto summ = [&](ll x)
        {
            ll sum = 0;
            for(ll i = x; i ; i -= (i & (-i)))
            {
                sum += B[i];
            }
            return sum;
        };
        auto find_greater = [&](ll r)
        {
            ll L = 1, R = k;
            ll ans = -1;
            while(L <= R)
            {
                ll M = L + (R - L) / 2;
                if(summ(M) > r)
                {
                    ans = M;
                    R = M - 1;
                }
                else
                {
                    L = M + 1;
                }
            }
            return ans;
        };
        for(ll i = 1; i <= k; i++)  update(i, 1);
        priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> run;
        vector<ll> tot(k + 1);
        for(ll i = 0; i < arrival.size(); i++)
        {
            while(!run.empty() && run.top()[0] <= arrival[i])
            {
                auto [time, idx] = run.top();
                run.pop();
                update(idx, 1);
            }
            if(summ(k) == 0)  continue;
            ll r = (i % k) + 1;
            cout << r << endl;
            ll to_assign = -1;
            ll val = 0;
            if(r > 1)   val = summ(r - 1);
            to_assign = find_greater(val);
            if(to_assign == -1)
            {
                to_assign = find_greater(0);
            }
            update(to_assign, -1);
            run.push({arrival[i] + load[i], to_assign});
            tot[to_assign]++;
        }
        ll maxx = *max_element(tot.begin(), tot.end());
        vector<int> ans;
        for(int i = 1; i <= k; i++)
        {
            if(tot[i] == maxx)  ans.push_back(i - 1);
        }
        return ans;
    }
};