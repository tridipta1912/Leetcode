class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int L = 0;
        int R = 1e9;
        int ans = -1;
        
        auto func = [&](int val)
        {
            int parts = 1, cur = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] > val) return false;
                if(nums[i] + cur > val) parts++, cur = nums[i];
                else
                {
                    cur += nums[i];
                }
            }
            return (parts <= k);
        };

        while(L <= R)
        {
            int M = L + (R - L) / 2;
            if(func(M))
            {
                ans = M;
                R = M - 1;
            }
            else
            {
                L = M + 1;
            }
        }

        return ans;
    }
};