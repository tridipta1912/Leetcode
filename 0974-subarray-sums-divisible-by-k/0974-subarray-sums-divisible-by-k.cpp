class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        vector<int> mp(k);
        mp[0]++;
        for(auto x : nums)
        {
            sum += ((x % k) + k) % k;
            sum %= k;
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};