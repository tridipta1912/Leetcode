class Solution {
public:
    int partitionDisjoint(vector<int>& nums) 
    {
        vector<int> minimum(nums.size());
        int k = 1e9;

        for(int i = nums.size() - 1; i >= 0 ; i--)
        {
            k = min(k, nums[i]);
            minimum[i] = k;
        }

        k = 0;
        for(int i = 0; i < (nums.size() - 1); i++)
        {
            k = max(k, nums[i]);
            if(k <= minimum[i + 1]) return (i + 1);
        }

        return nums.size();
    }
};