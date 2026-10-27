class Solution {
public:
    string getPermutation(int n, int k) {
        using ll = long long;
        vector<ll> fact(n + 1);
        fact[0] = 1;
        for(int i = 1; i < n; i++)  fact[i] = fact[i - 1] * i;
        string ans = "";
        set<ll> mst;
        for(int i = 1;i <= n; i++)  mst.insert(i);
        for(int i = 1; i <= n; i++)
        {
            ll tt = fact[n - i];
            tt = ((k + tt - 1) / tt);
            multiset<ll> nst;
            for(int i = 1; i < tt; i++) nst.insert(*mst.begin()), mst.erase(mst.begin());
            ans += to_string(*mst.begin());
            mst.erase(mst.begin());
            for(auto nums : nst)    mst.insert(nums);
            k -= (tt - 1) * fact[n - i];
        }
        return ans;
    }
};