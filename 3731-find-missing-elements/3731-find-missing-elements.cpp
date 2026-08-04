class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 1; i < nums.size(); i++)
        {
            int cur = nums[i - 1];
            while(nums[i] - cur > 1)   cur++, ans.push_back(cur);
        }
        return ans;
    }
};