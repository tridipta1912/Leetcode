class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        bool ch = false;
        for(auto x : nums)  ans ^= x, ch |= (x > 0);
        if(ans)
        {
            return nums.size();
        }
        return ((ch) ? nums.size() - 1 : 0);
    }
};