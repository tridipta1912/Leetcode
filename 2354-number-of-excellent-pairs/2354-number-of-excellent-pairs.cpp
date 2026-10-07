class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        using ll = long long;
        vector<ll> cnt(32);
        ll ans = 0;
        unordered_set<ll> st(nums.begin(), nums.end());
        for(auto x : st)  
        {
            ll bitt = __builtin_popcountll(x);
            cnt[bitt]++;
        }
        for(ll j = 30; j >= 0; j--) cnt[j] += cnt[j + 1];
        for(auto x : st)
        {
            ll bitt = k - __builtin_popcountll(x);
            bitt = max(bitt, 0LL);
            if(bitt <= 31) ans += cnt[bitt];
        }
        return ans;
    }
};