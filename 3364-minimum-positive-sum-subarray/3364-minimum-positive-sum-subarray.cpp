class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = 1e9;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int sum = 0, len = 0;
            for(int j = i; j < n; j++)
            {
                sum += nums[j];
                len++;
                if(len >= l && len <= r && sum > 0) ans = min(ans, sum);
                if(len == r)    break;
            }
        }
        if(ans == 1e9)  return -1;
        return ans;
    }
};