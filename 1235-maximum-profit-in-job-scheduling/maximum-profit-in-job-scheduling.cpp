class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<array<int, 3>> arr;
        for(int i = 0; i < startTime.size(); i++)   arr.push_back({startTime[i], endTime[i], profit[i]});
        sort(arr.begin(), arr.end(), [](array<int, 3> &a, array<int, 3> &b)
        {
            return (a[1] < b[1]);
        });
        vector<int> dp(startTime.size());
        for(int i = 0; i < startTime.size(); i++)
        {
            int L = 0, R = i - 1;
            int idx = -1;
            while(L <= R)
            {
                int M = L + (R - L) / 2;
                if(arr[M][1] <= arr[i][0])
                {
                    idx = M;
                    L = M + 1;
                }
                else
                {
                    R = M - 1;
                }
            }
            dp[i] = arr[i][2];
            if(i > 0)   dp[i] = max(dp[i], dp[i - 1]);
            if(idx != -1)   dp[i] = max(dp[i], dp[idx] + arr[i][2]);
        }
        return dp.back();
    }
};