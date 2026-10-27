class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        auto isSquare = [&](int x, int y)
        {
            long long val = x + y;
            long long sq = sqrt(val);
            return ((sq * sq) == val);
        };
        
        int n = nums.size();
        int M = (1 << n);
        vector<vector<int>> dp(M, vector<int>(n, 0));
        for(int i = 0; i < n; i++) dp[1 << i][i] = 1;
        int ans = 0;
        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if((i >> j) & 1)
                {
                    for(int k = 0; k < n; k++)
                    {
                        if(!((i >> k) & 1) && isSquare(nums[j], nums[k]))   
                        {
                            dp[i | (1 << k)][k] += dp[i][j];
                        }
                    }
                }
                if(i == M - 1)  ans += dp[i][j];
            }
        }
        unordered_map<int, int> cnt;
        for(auto x : nums)
        {
            cnt[x]++;
            ans /= cnt[x];
        }
        return ans;
    }
};