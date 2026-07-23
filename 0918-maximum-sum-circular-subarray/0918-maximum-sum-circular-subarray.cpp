class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = -1e9, sum = 0, tot = 0, ans1 = -1e9, sum1 = -1e9;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            sum1 -= nums[i];

            tot += nums[i];
            
            ans = max(ans, sum);
            ans1 = max(ans1, sum1);

            if(sum < 0) sum = 0;
            if(sum1 < 0)    sum1 = 0;
        }
        
        if(ans <= 0)    
        {
            return ans;
        }
        ans = max(ans, tot + ans1);
        return ans;
    }
};