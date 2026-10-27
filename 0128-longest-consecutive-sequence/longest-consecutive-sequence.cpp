class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cur = 0, len = 0, ans = 0;

        for(auto x: nums)
        {
            if(len == 0)
            {
                cur = x;
                len++;
            }
            else if (x == cur)
            {
                continue;
            }
            else if (x == cur + 1)
            {
                cur = x;
                len++;
            }
            else
            {
                cur = x;
                len = 1;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};
