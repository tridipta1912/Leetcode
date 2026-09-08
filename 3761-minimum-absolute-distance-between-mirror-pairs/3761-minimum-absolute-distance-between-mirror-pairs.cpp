class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        using ll = int;
        unordered_map<ll, ll> mp;
        mp.reserve(nums.size());
        auto rev = [&](ll x)
        {
            ll cur = 0;
            while(x)
            {
                cur = (cur * 10 + x % 10);
                x /= 10;
            }
            return cur;
        };
        
        ll ans = 1e9;
        for(ll i = 0; i < nums.size(); i++)
        {
            ll x = nums[i];
            auto it = mp.find(x);
            if(it != mp.end()) ans = min(ans, i - it->second);
            mp[rev(nums[i])] = i;
        }
        
        return (ans == 1e9 ? -1 : ans);
    }
};