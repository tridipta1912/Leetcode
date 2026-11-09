class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        auto find = [&](vector<int> &a)
        {
            int n = a.size();
            int summ = accumulate(a.begin(), a.end(), 0) + 1;
            vector<bool> dp(summ + 1);
            vector<int> dp1(summ + 1, -1);
            dp[0] = 1;
            dp1[0] = 0;
            for(int i = 0; i < n; i++)
            {
                vector<bool> ndp = dp;
                vector<int> ndp1 = dp1;
                for(int j = summ - 1; j >= 0; j--)
                {
                    if(dp[j])
                    {
                        int val1 = abs(j + a[i]);
                        int val2 = abs(j - a[i]);
                        ndp[val1] = true; ndp[val2] = true;
                        ndp1[val1] = max(ndp1[val1], dp1[j] + a[i]);
                        ndp1[val2] = max(ndp1[val2], dp1[j] + a[i]);
                    }
                }
                swap(dp, ndp);
                swap(dp1, ndp1);
            }
            return dp1;
        };

        int n1 = (n / 2);
        vector<int> a1, a2;
        for(int i = 0; i < n1; i++)  a1.push_back(rods[i]);
        for(int i = n1; i < n; i++)  a2.push_back(rods[i]);

        vector<int> mp1 = find(a1);
        vector<int> mp2 = find(a2);

        if(mp1.size() > mp2.size()) swap(mp1, mp2);

        int ans = 0;

        for(int x = 1; x < mp1.size(); x++)
        {
            if(mp1[x] == -1)    continue;
            if(x < mp2.size() && mp2[x] != -1) ans = max(ans, mp2[x] + mp1[x]);
        }
        ans /= 2;
        
        return ans;
    }
};