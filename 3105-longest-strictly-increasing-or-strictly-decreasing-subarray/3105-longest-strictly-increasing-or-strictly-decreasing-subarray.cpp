class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, ans = 1;
        for(int i = 0; i + 1 < nums.size(); i++)
        {
            if(nums[i] > nums[i + 1])   
            {
                cnt1++;
            }
            else cnt1 = 0;

            if (nums[i] < nums[i + 1])
            {
                cnt2++;
            }
            else cnt2 = 0;
            ans = max(ans, max(cnt1, cnt2) + 1);
        }
        return ans;
    }
};