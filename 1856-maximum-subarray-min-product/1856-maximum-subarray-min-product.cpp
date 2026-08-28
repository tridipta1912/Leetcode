class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        using ll = long long;
        constexpr ll MOD = 1e9 + 7;
        ll n = nums.size();
        vector<ll> L, R;
        vector<ll> left, right;
        for(ll i = 0; i < n; i++)
        {
            while(!L.empty() && nums[L.back()] >= nums[i])
            {
                L.pop_back();
            }
            left.push_back((L.empty()) ? -1 : L.back());
            L.push_back(i);
        }
        for(ll i = n - 1; i >= 0; i--)
        {
            while(!R.empty() && nums[R.back()] > nums[i])
            {
                R.pop_back();
            }
            right.push_back((R.empty()) ? n : R.back());
            R.push_back(i);
        }
        reverse(right.begin(), right.end());
        vector<ll> pref(n);
        for(ll i = 0; i < n; i++)   
        {
            pref[i] = nums[i];
            if(i)   pref[i] += pref[i - 1];
        }

        ll ans = 0;
        for(ll i = 0; i < n; i++)
        {
            ll tot = 0;
            if(right[i]) tot += pref[right[i] - 1];
            if(left[i] != -1)  tot -= pref[left[i]];
            ans = max(ans, (tot * nums[i]));
        }

        ans = (ans % MOD + MOD) % MOD;
        return ans;
    }
};