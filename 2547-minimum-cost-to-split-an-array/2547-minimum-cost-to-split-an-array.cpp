class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        using ll = int;
        ll n = nums.size();
        vector<ll> dp(n + 1, 2e9);
        vector<ll> freq(n + 1, 0);
        dp[0] = 0;
        for(ll i = 0; i < n; i++)
        {
            ll val = 0;
            for(ll j = i; j < n; j++)
            {
                freq[nums[j]]++;
                if(freq[nums[j]] > 2)    val++;
                else if (freq[nums[j]] == 2)  val += 2;
                dp[j + 1] = min(dp[j + 1], dp[i] + k + val);
            }
            for(ll j = i; j < n; j++)
            {
                freq[nums[j]]--;
            }
        }
        return dp[n];
    }
};