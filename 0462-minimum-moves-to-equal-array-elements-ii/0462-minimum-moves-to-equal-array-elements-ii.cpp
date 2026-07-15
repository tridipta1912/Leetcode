using ll = long long;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        ll ans = 1e18;
        sort(nums.begin(), nums.end());
        ll sum = 0, pref = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)  sum += nums[i];
        for(int i = 0; i < n; i++)
        {
            pref += nums[i];
            ll ans1 = ((i + 1) * (ll)nums[i]) - pref;
            ans1 += (sum - pref) - ((n - i - 1) * (ll)nums[i]);
            ans = min(ans, ans1);
        }

        return (int)ans;
    }
};