class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int ans = 0;
        map<int, int> freq;
        map<int, array<int, 2>> dp;
        for(auto x : nums)  freq[x]++;
        for(auto &[x, f] : freq)
        {   
            dp[x][0] = max(dp[x - 1][0] , dp[x - 1][1]) + 1;
            if(f > 1)   dp[x + 1][1] = dp[x][0] + 1;
            else        dp[x + 1][1] = dp[x][1] + 1;
        }
        for(auto &[x, arr] : dp)    ans = max(ans, max(arr[0], arr[1]));
        return ans;
    }
};