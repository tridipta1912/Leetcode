class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        int cnt = 0;
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int> ndp;
            for(auto x : dp)
            {
                ndp[x.first + nums[i]] += x.second;
                ndp[x.first - nums[i]] += x.second;
            }
            swap(dp, ndp);
        }
        return dp[target];
    }
};