class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        using ll = int;
        ll n = nums.size();
        vector<ll> a;
        map<ll, ll> mp;
        for(auto x : nums)
            {
                if(!a.empty() && a.back() == x)
                {
                    continue;
                }
                a.push_back(x);
                mp[x]++;
            }
        ll ans = 0;
            for(auto [x, y] : mp)ans += (y == 1);
        return ans;
    }
};