class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        pair<int, int> pa = {(int)(1e8), 0};
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                for(int k = j + 1; k < nums.size(); k++)
                {
                    pa = min(pa, {(int)abs(nums[i] + nums[j] + nums[k] - target), nums[i] + nums[j] + nums[k]});
                }
            }
        }
        return pa.second;
    }
};