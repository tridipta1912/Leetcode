class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        using ll = int;
        unordered_map<ll, ll> pos;
        ll m = target.size();

        for (ll i = 0; i < m; i++) pos[target[i]] = i;

        vector<ll> seq;

        for (ll x : arr) 
        {
            if (pos.count(x))   seq.push_back(pos[x]);
        }

        vector<ll> lis;

        for (auto x : seq) 
        {
            auto it = lower_bound(lis.begin(), lis.end(), x);

            if (it == lis.end())    lis.push_back(x);
            else                    *it = x;
        }

        return m - lis.size();
    }
};