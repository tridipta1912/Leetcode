class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i && nums[i] != nums[i - 1] + 1) break;
            sum += nums[i];
        }
        sort(nums.begin(), nums.end());
        for(auto x : nums)  if(x == sum)    sum++;
        return sum;
    }
};