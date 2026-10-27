class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) 
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> dq; 
        int minLength = 1e9+10;

        for (int i = 0; i <= n; ++i) 
        {
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) 
            {
                minLength = min(minLength, i - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) 
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return minLength == 1e9+10 ? -1 : minLength;
    }
};