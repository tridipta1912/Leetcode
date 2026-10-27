class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() <= 4) return 0;
        int i = 0, j = nums.size() - 4;
        int ans = 2e9;
        while(j != nums.size())
        {
            ans = min(ans, nums[j] - nums[i]);
            i++, j++;
        }
        return ans;
    }
};