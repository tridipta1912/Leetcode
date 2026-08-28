class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        using ll = long long;
        map<ll, ll> mp;
        
        ll n = nums.size();
        ll ans = 0;
        
        for(ll i = 0; i < n; i++)
        {
            map<ll, ll> nmp;
            for(auto [a, b] : mp)
            {
                ll v = gcd(nums[i], a);
                nmp[v] += b;
            }
            nmp[nums[i]]++;
            swap(nmp, mp);
            ans += mp[k];
        }

        return ans;
    }
};