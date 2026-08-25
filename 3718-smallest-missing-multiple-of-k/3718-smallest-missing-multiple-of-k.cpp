class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cur = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % k == 0)
            {
                nums[i] /= k;
                if(nums[i] - cur > 1)
                {
                    return ((cur + 1) * k);
                }
                cur = max(cur, nums[i]);
            }
        }
        
        return ((cur + 1) * k);
    }
};