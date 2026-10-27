class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        using ll = long long;
        ll n = nums.size();
        map<ll, ll> mp;
        mp[0] = -1;
        ll ans = -1, sum = 0, tot = 0;
        for(auto y : nums)  tot += y;
        x = (tot - x);
        if(x == 0)  return n;
        for(ll i = 0; i < n; i++)
        {
            sum += nums[i];
            if(mp.count(sum - x))   ans = max(ans, i - mp[sum - x]);
            mp[sum] = i;
        }
        if(ans == -1)   return ans;
        return (n - ans);
    }
};