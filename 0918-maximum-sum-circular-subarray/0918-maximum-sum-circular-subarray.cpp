class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = -1e9, sum = 0, tot = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            tot += nums[i];
            ans = max(ans, sum);
            if(sum < 0) 
            {
                sum = 0;
            }
            nums[i] *= -1;
        }
        
        int sum1 = 0, ans1 = 0;
        for(int i = 0; i < n; i++)
        {
            sum1 += nums[i];
            ans1 = max(ans1, sum1);
            if(sum1 < 0) 
            {
                sum1 = 0;
            }
        }

        if(ans <= 0)    
        {
            return ans;
        }
        ans = max(ans, tot + ans1);
        return ans;
    }
};