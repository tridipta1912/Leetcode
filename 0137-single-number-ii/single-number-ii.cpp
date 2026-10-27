class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;

        for(auto num: nums)
        {
            m[num]++;
        }

        for(auto nums: m)
        {
            if(nums.second==1)    return nums.first;
        }
        return 0;
    }
};