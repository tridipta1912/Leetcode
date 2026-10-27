class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans(0), n(nums.size());
        int m = *max_element(nums.begin(), nums.end());
        vector<int> r(m + 1);
        for(int i = 0; i < n; i++)
        {
            int val = 0;
            for(int j = i; j < n; j++)  
            {
                if(!r[nums[j]]) val++, r[nums[j]] = 1;
                ans += (val * val);
            }
            for(int j = i; j < n; j++)  r[nums[j]] = 0;
        }
        return ans;
    }
};