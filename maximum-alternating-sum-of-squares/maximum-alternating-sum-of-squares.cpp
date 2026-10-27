class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto &x : nums) if(x < 0)   x *= -1;
        sort(nums.begin(), nums.end());
        long long ans = 0;
        deque<int> dq(nums.begin(), nums.end());
        while(!dq.empty())
        {
            if(dq.size() % 2 == nums.size() % 2)
            {
                ans += (dq.back() * dq.back());
                dq.pop_back();
            }
            else
            {
                ans -= (dq.front() * dq.front());
                dq.pop_front();
            }
        }

        return ans;
    }
};