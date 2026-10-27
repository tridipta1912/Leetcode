class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<vector<int>> freq(10, vector<int>(10, 0));
        int ans = 0;
        for(auto nums: dominoes)
        {
            if(nums[1] < nums[0])   swap(nums[0], nums[1]);
            ans += freq[nums[0]][nums[1]];
            freq[nums[0]][nums[1]]++;
        }
        return ans;
    }
};