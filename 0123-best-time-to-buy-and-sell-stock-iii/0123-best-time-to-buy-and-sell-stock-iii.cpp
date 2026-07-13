class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       vector<int> pref(n), suff(n); 
       vector<int> minn(n, 1e9), maxx(n, -1e9);
       for(int i = 0; i < n; i++)
       {
            minn[i] = prices[i];
            if(i > 0)   
            {
                pref[i] = prices[i] - minn[i - 1];
                minn[i] = min(minn[i - 1], minn[i]);
                pref[i] = max(pref[i], pref[i - 1]);
            }
       }
       for(int i = n - 1; i >= 0; i--)
       {
            maxx[i] = prices[i];
            if(i + 1 < n)
            {
                suff[i] = maxx[i + 1] - prices[i];
                suff[i] = max(suff[i], suff[i + 1]);
                maxx[i] = max(maxx[i], maxx[i + 1]);
            }
       }

       int ans = 0;
       for(int i = 0; i + 1 < n; i++)    ans = max(ans, (int)(pref[i] + suff[i + 1]));
       for(int i = 0; i < n; i++)   ans = max(ans, pref[i]), ans = max(ans, suff[i]);

       return ans;
    }
};