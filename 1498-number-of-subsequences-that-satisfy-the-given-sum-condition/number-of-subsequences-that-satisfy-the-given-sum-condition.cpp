class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        using ll = long long;
        const ll MOD = 1e9 + 7;

        ll n = nums.size();
        vector<ll> pow2(n + 1, 1LL);
        for(int i = 1; i <= n; i++)
        {
            pow2[i] = (2 * pow2[i - 1]);
            pow2[i] %= MOD;
        }

        sort(nums.begin(), nums.end());
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            ll L = i;
            ll R = n - 1;
            ll idx = -1;
            while(L <= R)
            {
                ll M = L + (R - L) / 2;
                if(nums[M] + nums[i] <= target)
                {
                    idx = M;
                    L = M + 1;
                }
                else
                {
                    R = M - 1;
                }
            }
            cout << i << ' ' << idx << endl;
            if(idx == -1)   continue;
            ans += pow2[idx - i];
            ans %= MOD;
        }

        return ans;
    }
};