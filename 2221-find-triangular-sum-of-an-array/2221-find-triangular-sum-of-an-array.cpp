class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size() > 1)
        {
            vector<int> n_nums;
            for(int i = 0; i + 1 < nums.size(); i++)    n_nums.push_back((nums[i] + nums[i + 1]) % 10);
            swap(nums, n_nums);
        }
        return nums[0];
    }
};