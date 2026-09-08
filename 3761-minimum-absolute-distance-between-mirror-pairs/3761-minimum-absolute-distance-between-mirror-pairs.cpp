class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        using ll = int;
        map<ll, ll> mp;
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
            if(mp.find(x) != mp.end())  ans = min(ans, i - mp[x]);
            mp[rev(nums[i])] = i;
        }
        
        return (ans == 1e9 ? -1 : ans);
    }
};