class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        using ll = long long;
        priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
        ll S = 0;
        for(auto &x : nums)
        {
            S += max(x, 0);
            if(x < 0)   x *= -1;
        }
        sort(nums.begin(), nums.end());
        pq.push({nums[0], 0});
        ll cur = 0;
        while(--k)
        {
            auto [s, i] = pq.top();
            pq.pop();
            cur = s;

            if(i + 1 < nums.size())
            {
                pq.push({s + nums[i + 1], i + 1});
                pq.push({s - nums[i] + nums[i + 1], i + 1});
            }
        }
        S -= cur;
        return S;
    }
};