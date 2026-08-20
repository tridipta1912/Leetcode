class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int L = 0, R = nums.back() - nums.front();
        int ans = 0;
        auto check = [&](int x)
        {
            int cnt = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                auto it = upper_bound(nums.begin(), nums.end(), nums[i] + x);
                int dist = it - nums.begin() - i - 1;
                cnt += dist;
            }
            return (cnt >= k);
        };

        while(L <= R)
        {
            int M = L + (R - L) / 2;
            if(check(M))
            {
                ans = M;
                R = M - 1;
            }
            else
            {
                L = M + 1;
            }
        }
        return ans;
    }
};