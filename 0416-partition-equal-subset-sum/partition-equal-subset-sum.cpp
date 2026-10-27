class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)    sum += nums[i];

        if(sum % 2 == 1)    return false;
        sum /= 2;

        vector<bool> dp(sum + 1, 0);
        for(auto val : nums)
        {
            for(int i = sum; i >= 0; i--)
            {
                if((i + val) <= sum && dp[i])   dp[i + val] = true;
            }
            if(val <= sum)  dp[val] = true;
        }

        return (dp[sum]);
    }
};