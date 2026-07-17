class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int N = *max_element(nums.begin(), nums.end());
        vector<long long> cnt(N + 1), tot(N + 1);
        vector<int> gcdV;
        for(auto x : nums)  cnt[x]++;
        vector<vector<long long>> D(N + 1);
        for(int i = 1; i <= N; i++)
        {
            long long ct = 0;
            for(int j = i; j <= N; j += i)
            {
                ct += cnt[j];
                if(i != 1) D[j].push_back(i);
            }
            tot[i] += (ct * (ct - 1)) / 2;
        }
        
        for(int i = N; i >= 1; i--)
        {
            for(auto x : D[i])  tot[i / x] -= tot[i];
        }

        for(int i = 1; i <= N; i++) 
        {
            tot[i] += tot[i - 1];
        }

        for(auto x : queries)
        {
            x++;
            int L = 1, R = N;
            int ans = -1;
            while(L <= R)
            {
                int M = L + (R - L) / 2;
                if(tot[M] >= x)
                {
                    ans = M;
                    R = M - 1;
                }
                else
                {
                    L = M + 1;
                }
            }
            gcdV.push_back(ans);
        }
        return gcdV;
    }
};