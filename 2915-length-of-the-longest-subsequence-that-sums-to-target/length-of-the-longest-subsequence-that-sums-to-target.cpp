class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 0;
        for(auto c : nums)
        {
            for(int i = target - c; i >= 0; i--)
            {
                if(dp[i] != -1) dp[i + c] = max(dp[i + c], dp[i] + 1);
            }
        }
        return dp[target];
    }
};