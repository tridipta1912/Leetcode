class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> nums1;
        int c = 0;
        for(int  i = 0; i < nums.size();i++)
        {
            nums1.push_back(nums[i]);
            if(nums[i]!=val)
            {
                nums[c] = nums1[i];
                c++;
            }
        }

        return c;
    }
};