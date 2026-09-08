class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        using ll = long long;
        unordered_map<ll, ll> mp;
        auto rev = [&](ll x)
        {
            string r = to_string(x);
            reverse(r.begin(), r.end());
            return stoi(r);
        };
        
        ll ans = 1e9;
        for(ll i = 0; i < nums.size(); i++)
        {
            ll x = nums[i];
            while (x <= 1e9)
            {
                if(mp.find(x) != mp.end())  ans = min(ans, i - mp[x]);
                x *= 10;
            }
            mp[rev(nums[i])] = i;
        }
        return (ans == 1e9 ? -1 : ans);
    }
};