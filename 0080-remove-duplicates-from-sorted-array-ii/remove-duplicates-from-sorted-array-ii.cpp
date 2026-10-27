class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0, last = -1e9;
        int pt = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != last)
            {
                last = nums[i];
                cur = 1;
                nums[pt] = nums[i];
                pt++;
            }
            else if(nums[i] == last)
            {
                if(cur >= 2) continue;
                cur++;
                nums[pt] = nums[i];
                pt++;
            }
        }

        return pt;
    }
};