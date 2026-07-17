class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        if(nums.size() == 1)    return nums[0];

        int L = 0;
        int R = nums.size() / 2 - 1;
        int ans = nums.back();

        while(L <= R)
        {
            int M = L + (R - L) / 2;
            
            if(nums[2 * M] != nums[2 * M + 1])
            {
                ans = nums[2 * M];
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