class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // Sort the input to potentially improve efficiency
        sort(nums.begin(), nums.end());

        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i <= target; ++i) {
            for (auto num : nums) {
                if (i + num <= target) {
                    // Check for potential overflow before updating dp
                    if (dp[i] <= LLONG_MAX - dp[i + num]) {
                        dp[i + num] += dp[i];
                    } else {
                        // Handle overflow case (depending on problem constraints)
                        dp[i + num] = LLONG_MAX;
                    }
                } else {
                    break; // Since nums is sorted, no need to check further
                }
            }
        }
        return static_cast<int>(dp[target]);
    }
};
