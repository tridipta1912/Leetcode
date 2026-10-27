class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        if (nums.empty()) 
        {
            return 0;
        }

        vector<int> pre(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0) 
            {
                pre[i] = nums[i];
            } 
            else 
            {
                pre[i] = nums[i] + pre[i - 1];
            }
        }

        int x = 1e9;
        auto it = lower_bound(pre.begin(), pre.end(), target);
        if (it != pre.end()) 
        {
            x = distance(pre.begin(), it) + 1;
        }

        for (int i = 1; i < nums.size(); i++) 
        {
            auto it = lower_bound(pre.begin() + i, pre.end(), target + pre[i - 1]);
            if (it != pre.end()) 
            {
                int y = distance(pre.begin(), it) - (i - 1);
                x = std::min(x, y);
            }
        }

        return x > nums.size() ? 0 : x;
    }
};
