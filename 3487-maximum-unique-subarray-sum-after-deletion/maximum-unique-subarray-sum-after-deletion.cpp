class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        if(*max_element(nums.begin(), nums.end()) < 0)
        {
            return *max_element(nums.begin(), nums.end());
        }
        for(auto v : st)
        {
            ans += max(v, 0);
        }
        return ans;
    }
};