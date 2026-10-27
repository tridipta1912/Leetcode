class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cur = 0;
        for(auto v : nums)
        {
            if(v == 0)  cur = 0;
            else        cur++;
            ans = max(ans, cur);
        }
        return ans;
    }
};