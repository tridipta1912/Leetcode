class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> dp(n);
        dp[0] = 1;

        int k = primes.size();
        vector<int> idx(k, 0); 
        vector<long long> val(primes.begin(), primes.end()); 

        for (int i = 1; i < n; ++i) {
            long long next = *min_element(val.begin(), val.end());
            dp[i] = next;

            for (int j = 0; j < k; ++j) {
                if (val[j] == next) {
                    idx[j]++;
                    val[j] = dp[idx[j]] * primes[j];
                }
            }
        }

        return dp[n - 1];
    }
};