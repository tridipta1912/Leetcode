class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 0, even1 = 0, odd1 = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == 0)
            {
                even = max(even, odd + 1);
                even1++;
            }
            else
            {
                odd = max(odd, even + 1);
                odd1++;
            }
        }
        return max({even, odd, even1, odd1});
    }
};