class Solution {
public:
    int minMoves2(vector<int>& nums) {
        using ll = int;
        ll ans = 0;
        ll n = nums.size();
        sort(nums.begin(), nums.end());
        int med = nums[n / 2];
        for(auto &x : nums) ans += abs(med - x);
        return ans;
    }
};