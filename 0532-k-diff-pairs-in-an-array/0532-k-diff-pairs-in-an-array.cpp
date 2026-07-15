class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> dp;
        for(auto x : nums)  dp[x]++;
        int ans = 0;
        if(k == 0)  
        {
            for(auto [x, y] : dp)   ans += min(((y * (y - 1)) / 2), 1);
            return ans;
        }
        for(auto x : nums)  ans += min(dp[x + k], 1), dp[x + k] = 0;
        return ans;
    }
};