class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities)
    {
        auto predicate = [&](int x)
        {
            int L = 0;
            vector<int> quantity = quantities;
            for(int i = 0; i < n; i++)
            {
                if(L == quantity.size())    return true;
                quantity[L] -= min(x, quantity[L]);
                if(quantity[L] == 0)  L++;
            }
            return (L == quantity.size());
        };

        int L = 0, R = 1e5;
        int ans;

        while(L <= R)
        {
            int M = L + (R - L)/2;
            if(predicate(M))
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