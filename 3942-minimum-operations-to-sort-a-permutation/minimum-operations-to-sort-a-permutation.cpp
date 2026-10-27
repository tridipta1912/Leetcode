class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bool is_Asc = true;
        int idx = -1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] != (nums[i - 1] + 1) % n)  is_Asc = false;
            if(nums[i] == 0)   idx = i;
        }
        if(is_Asc)
        {
            if(idx == -1)   return 0;
            return min(n - nums.front(), nums.front() + 2);
        }
        bool is_Dsc = true;
        for(int i = 1; i < n; i++)
        {
            if((nums[i] + 1) % n != nums[i - 1])  is_Dsc = false;
        }
        if(is_Dsc)
        {
            return min(n - nums.back() + 1, nums.back() + 1);
        }
        return -1;
    }
};