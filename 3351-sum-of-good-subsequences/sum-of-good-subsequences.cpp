class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        long long MOD = 1e9 + 7;
        map<long long, long long> dp, freq;
        long long ans = 0;

        for (long long i = 0; i < nums.size(); i++) {
            // Ensure map keys are accessed safely
            long long prev = nums[i] - 1;
            long long next = nums[i] + 1;

            long long val = ((dp[prev] + (1LL * freq[prev] * nums[i]) % MOD) % MOD);
            long long val1 = ((dp[next] + (1LL * freq[next] * nums[i]) % MOD) % MOD);

            // Update answer and data structures
            ans = (ans + val + val1 + nums[i]) % MOD;
            dp[nums[i]] = (((dp[nums[i]] + val) % MOD + val1) % MOD + nums[i]) % MOD;
            freq[nums[i]] = (freq[nums[i]] + freq[prev] + freq[next] + 1) % MOD;
        }
        
        int answer = ans % MOD;
        return answer;
    }
};
