class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9, sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};