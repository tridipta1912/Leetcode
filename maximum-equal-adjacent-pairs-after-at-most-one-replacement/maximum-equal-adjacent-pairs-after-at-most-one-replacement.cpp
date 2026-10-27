class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        using ll = int;
        map<array<ll, 2>, ll> freq;
        unordered_map<ll, ll> eq;
        
        for(ll i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1]) eq[nums[i]]++;
            array<ll, 2> x = {nums[i], nums[i - 1]};
            if(x[0] < x[1]) swap(x[0], x[1]);
            freq[x]++;
        }
        
        ll ans = 0;
    
        for(ll i = 1; i < nums.size(); i++)
        {
            array<ll, 2> x = {nums[i], nums[i - 1]};
            if(x[0] < x[1]) swap(x[0], x[1]);
            if(x[0] != x[1]) ans = max(ans, freq[x]);
        }
        for(auto [x, y] : eq) ans += y;
        return ans;
    }
};