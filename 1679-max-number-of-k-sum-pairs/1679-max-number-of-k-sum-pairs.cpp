class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        using ll = long long;
        map<ll, ll> mp;
        for(auto x : nums)  mp[x]++;

        ll ans = 0;
        for(auto [a, val] : mp)
        {
            ll c = k - a;
            if(c > a)   ans += min(mp[a], mp[c]);
            else if (a == c)    ans += (val / 2);
        }
        return ans;
    }
};