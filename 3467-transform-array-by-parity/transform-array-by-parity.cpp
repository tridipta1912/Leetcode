class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for(auto &x : nums) x %= 2;
        sort(nums.begin(), nums.end());
        return nums;
    }
};