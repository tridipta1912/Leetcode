class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int cur = 0;
        long long ans = 0;
        for(auto v : nums)
        {
            if(v == 0)
            {
                ans += (cur + 1);
                cur++;
            }
            else
            {
                cur = 0;
            }
        }
        return ans;
    }
};