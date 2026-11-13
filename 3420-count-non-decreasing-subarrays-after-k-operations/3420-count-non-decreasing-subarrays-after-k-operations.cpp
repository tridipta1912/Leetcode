class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        using ll = long long;
        ll n = nums.size();
        deque<array<ll, 2>> dq;
        ll sum = 0, cur = 0, len = 0;
        ll ans = 0;
        for(ll i = n - 1; i >= 0; i--)
        {
            ll freq = 1;
            while(!dq.empty() && dq.front()[0] <= nums[i])
            {               
                auto [val, f] = dq.front();
                dq.pop_front();
                freq += f;
                sum -= (val * f);
            }
            len++;
            sum += nums[i] * freq;
            dq.push_front({nums[i], freq});
            sum -= nums[i];
            while(sum > k)
            {
                auto [val, f] = dq.back();
                dq.pop_back();
                sum -= val;
                sum += (nums[i + len - 1]);
                len--;
                if(f > 1)   dq.push_back({val, f - 1});
            }
            ans += len;
            // for(auto &[x, y] : dq)  cout << x << ',' << y << ' ';
            // cout << len << ' ' << sum << endl;
        }
        return ans;
    }
};