class Solution {
public:
    int maxProfit(vector<int>& prices) {
        using ll = long long;
        int maxx = -1e9;
        int ans = 0;
        for(ll i = prices.size() - 1; i >= 0; i--)
        {
            ans = max(ans, maxx - prices[i]);
            maxx = max(maxx, prices[i]);
        }
        return (ans);
    }
};