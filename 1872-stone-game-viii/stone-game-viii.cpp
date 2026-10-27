class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        using ll = long long;
        ll n = stones.size();
        for(ll i = 1; i < n; i++)   stones[i] += stones[i - 1];
        
        ll ans = stones.back();
        for(ll i = n - 2; i >= 1; i--)
        {
            ans = max(ans, stones[i] - ans);
        }
        return ans;
    }
};