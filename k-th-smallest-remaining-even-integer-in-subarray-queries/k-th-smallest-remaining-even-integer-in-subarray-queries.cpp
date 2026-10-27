class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        using ll = int;
        ll n = nums.size();
        vector<ll> pref(n);
        for(ll i = 0; i < n; i++)   
        {
            pref[i] += (nums[i] % 2 == 0);
            if(i)   pref[i] += pref[i - 1];
        }
        vector<int> answer;
        for(auto vec : queries)
        {
            ll l = vec[0], r = vec[1], k = vec[2];
            auto query = [&](ll x)
            {
                ll tot = (x / 2);
                if(x >= nums[l])
                {
                    ll dist = upper_bound(nums.begin(), nums.end(), x) - nums.begin() - 1;
                    ll r1 = min(r, dist);
                    if(x >= nums[0]) tot -= pref[r1];
                    if(l > 0)   tot += pref[l - 1];
                }
                return (tot >= k);
            };

            ll L = 2, R = INT_MAX;
            answer.emplace_back();
            while(L <= R)
            {
                ll M = L + (R - L) / 2;
                if(query(M))
                {
                    answer.back() = M;
                    R = M - 1;
                }
                else
                {
                    L = M + 1;
                }
            };
        }
        return answer;
    }
};