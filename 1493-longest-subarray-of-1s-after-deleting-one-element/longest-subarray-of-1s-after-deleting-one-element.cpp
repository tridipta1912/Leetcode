class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        using ll = long long;
        vector<ll> pref(nums.size()), suff(nums.size());
        for(ll i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)    pref[i] = 0;
            else
            {
                pref[i] = 1;
                if(i) pref[i] += pref[i - 1];
            }
        }
        for(ll i = nums.size() - 1; i >= 0; i--)
        {
            if(nums[i] == 0)    suff[i] = 0;
            else
            {
                suff[i] = 1;
                if(i + 1 < nums.size()) suff[i] += suff[i + 1];
            }
        }
        ll ans = 0;
        for(ll i = 0; i < nums.size(); i++)
        {
            ll x1 = 0, x2 = 0;
            if(i)   x1 += pref[i - 1];
            if(i + 1 < nums.size()) x2 += suff[i + 1];
            ans = max(ans, x1 + x2);
        }
        return ans;
    }
};