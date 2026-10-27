class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxx = 0;
        for(auto v : nums)  maxx |= v;
        int tot = (1 << nums.size());
        int ans = 0;
        for(int i = 0; i < tot; i++)
        {
            int orr = 0;
            for(int j = 0; j < nums.size(); j++)
            {
                if((1 << j) & i)    orr |= nums[j];
            }
            ans += (orr == maxx);
        }
        return ans;
    }
};