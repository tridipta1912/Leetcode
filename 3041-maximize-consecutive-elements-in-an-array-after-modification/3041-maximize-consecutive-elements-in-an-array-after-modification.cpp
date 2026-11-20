class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int ans = 0;
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx + 2, 0);
        vector<array<int, 2>> dp(mx + 2, {0, 0});
        
        for (auto x : nums) freq[x]++;
        
        for (int x = 1; x <= mx; x++) 
        {   
            int f = freq[x];
            if (f == 0) continue;
            
            dp[x][0] = max(dp[x - 1][0], dp[x - 1][1]) + 1;
            if (f > 1)  dp[x + 1][1] = dp[x][0] + 1;
            else        dp[x + 1][1] = dp[x][1] + 1;
        }
        
        for (auto &arr : dp) ans = max(ans, max(arr[0], arr[1]));
        return ans;
    }
};