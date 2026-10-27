class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        using ll = int;
        ll n = nums.size();
        vector<ll> minn = nums, maxx = nums;
        for(ll i = 1; i < n; i++)   maxx[i] = max(maxx[i], maxx[i - 1]);
        for(ll i = n - 2; i >= 0; i--)  minn[i] = min(minn[i], minn[i + 1]);

        for(ll i = 0; i < n; i++)
        {
            if(maxx[i] - minn[i] <= k)
            {
                return i;
            }
        }

        return -1;
    }
};