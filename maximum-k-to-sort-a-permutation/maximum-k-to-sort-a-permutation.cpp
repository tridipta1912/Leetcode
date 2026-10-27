class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = ~(0), ch = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i)    ans &= nums[i], ch = 1;
        }
        if(ch == -1) return 0;
        return ans;
    }
};