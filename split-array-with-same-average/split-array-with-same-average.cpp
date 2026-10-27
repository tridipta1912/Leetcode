class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        using ll = long long;
        ll S = accumulate(nums.begin(), nums.end(), 0);
        ll n = nums.size();
        ll k = (n / 2);
        vector<vector<bool>> dp(S + 1, vector<bool>(k + 1));
        dp[0][0] = 1;
        for(ll i = 0; i < n; i++)
        {
            ll x = nums[i];
            for(ll len = k; len >= 1; len--)
            {
                for(ll s = S; s >= x; s--)  if(dp[s - x][len - 1]) dp[s][len] = 1;
            }
        }
        for(ll i = 0; i <= S; i++)
        {
            for(ll j = 1; j <= k; j++)
            {
                if(dp[i][j] && i * n == j * S)  
                {
                    return true;
                }
            }
        }

        return false;
    }
};