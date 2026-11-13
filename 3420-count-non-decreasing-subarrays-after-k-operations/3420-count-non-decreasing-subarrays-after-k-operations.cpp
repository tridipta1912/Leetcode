class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        using ll = int;
        ll n = nums.size();
        deque<array<ll, 2>> dq;
        long long sum = 0, cur = 0, len = 0;
        long long ans = 0;
        for(ll i = n - 1; i >= 0; i--)
        {
            ll freq = 1;
            while(!dq.empty() && dq.front()[0] <= nums[i])
            {               
                auto [val, f] = dq.front();
                dq.pop_front();
                freq += f;
                sum -= ((long long)(val) * f);
            }
            len++;
            sum += (long long)nums[i] * freq;
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
        }
        return ans;
    }
};