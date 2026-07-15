class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        multiset<int> pref, suff;
        int n = nums.size();
        int ans = nums.back() - nums.front();
        for(int i = 0; i < n; i++)  suff.insert(nums[i] - k);
        for(int i = 0; i + 1 < n; i++)
        {
            suff.erase(suff.begin());
            pref.insert(nums[i] + k);
            ans = min(ans, max(*pref.rbegin(), *suff.rbegin()) - min(*pref.begin(), *suff.begin()));
        }
        return ans;
    }
};