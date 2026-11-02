class Solution {
public:
    int minMoves2(vector<int>& nums) {
        using ll = long long;
        ll sum = accumulate(nums.begin(), nums.end(), 0);
        ll sum1 = 0;
        ll ans = 1e18;
        ll n = nums.size();
        sort(nums.begin(), nums.end());
        for(ll i = 0; i < n; i++)
        {
            ans = min(ans, sum - (n - 2 * i) * nums[i] - sum1);
            sum1 += nums[i];
            sum -= nums[i];
        }
        return ans;
    }
};