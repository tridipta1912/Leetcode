class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        using ll = int;
        ll M = *max_element(nums.begin(), nums.end());
        vector<int> spf(M + 1, -1);
        for(ll i = 2; i <= M; i++)
        {
            if(spf[i] == -1)
            {
                for(ll j = i; j <= M; j += i)   if(spf[j] == -1) spf[j] = i;
            }
        }
        ll n = nums.size();
        vector<ll> last(M + 1);
        for(ll i = 0; i < n; i++)
        {
            ll x = nums[i];
            while(x > 1)
            {
                ll p = spf[x];
                last[p] = i;
                while(x % p == 0)   x /= p;
            }
        }
        ll maxx = 0;
        for(ll i = 0; i + 1 < n; i++)
        {
            ll x = nums[i];
            while(x > 1)
            {
                ll p = spf[x];
                maxx = max(maxx, last[p]);
                while(x % p == 0)   x /= p;
            }
            if(maxx == i)   return i;
        }
        return -1;
    }
};