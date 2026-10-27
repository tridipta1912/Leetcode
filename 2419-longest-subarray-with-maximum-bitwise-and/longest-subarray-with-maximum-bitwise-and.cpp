class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        int maxx = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == maxx)
            {
                cnt++;
                ans = max(ans, cnt);
            }
            else
            {
                cnt = 0;
            }
        }
        return ans;
    }
};