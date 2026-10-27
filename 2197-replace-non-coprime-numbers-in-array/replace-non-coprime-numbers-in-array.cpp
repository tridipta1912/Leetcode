class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        using ll = int;
        vector<ll> ans;
        ll n = nums.size();
        ans.push_back(nums[0]);
        for(ll i = 1; i < n; i++)
        {
            ll x = nums[i];
            while(!ans.empty() && __gcd(ans.back(), x) != 1)
            {
                ll r = ans.back();
                ans.pop_back();
                ll g = __gcd(r, x);
                x *= (r / g);
            }
            ans.push_back(x);
        }
        return ans;
    }
};