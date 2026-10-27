class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        using ll = long long;
        constexpr int MOD = 1e9 + 7;
        array<int, 32> freq;
        fill(begin(freq), end(freq), 0LL);
        
        for(auto x : nums)
        {
            for(ll i = 0; i < 32; i++)  if((x >> i) & 1)    freq[i]++;
        }

        ll ans = 0;
        for(int i = 0; i < k; i++)
        {
            int val = 0;
            for(int j = 0; j < 32; j++)
            {
                if(freq[j]) val |= (1 << j), freq[j]--;
            }
            ans += ((ll)val * (ll)val);
            ans %= MOD;
        }

        return ans;
    }
};