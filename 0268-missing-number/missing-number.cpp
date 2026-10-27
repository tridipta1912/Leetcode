class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int val = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            val ^= i;
            val ^= nums[i];
        }
        val ^= nums.size();
        return val;
    }
};