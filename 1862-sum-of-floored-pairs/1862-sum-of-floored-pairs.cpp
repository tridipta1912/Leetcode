class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        using ll = long long;
        long long ans = 0;
        int n = nums.size();
        int maxx = *max_element(nums.begin(), nums.end());
        
        vector<long long> freq(maxx + 1), pref(maxx + 1);
        for(auto x : nums)  freq[x]++;
        for(int i = 1; i <= maxx; i++)  pref[i] = freq[i] + pref[i - 1];

        for(int i = 1; i <= maxx; i++)
        {
            for(int j = i; j <= maxx; j += i)
            {
                int L = j;
                int R = min(j + i - 1, maxx);
                long long val = (j / i);
                val *= (pref[R] - pref[L - 1]), val %= MOD;
                val *= freq[i], val %= MOD;
                ans += val, ans %= MOD;
            }
        }

        return (int)ans;
    }
};