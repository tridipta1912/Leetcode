class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        using ll = long long;
        ll n = nums.size();
        vector<pair<ll, ll>> a(n);

        ll sum1 = 0, sum2 = 0;
        for(ll i = 0; i < n; i++)
        {
            a[i] = {nums[i], cost[i]};
            sum1 += a[i].first * a[i].second;
            sum2 += a[i].second;
        }
        sort(a.begin(), a.end(), greater<pair<ll, ll>>());

        ll ans = 1e18;

        ll cur1 = 0, cur2 = 0;
        for(ll i = 0; i < n; i++)
        {
            ll Nr = sum1 - 2 * cur1;
            ll Dr = sum2 - 2 * cur2;
            ans = min(ans, -Nr + a[i].first * Dr);
            cur1 += a[i].first * a[i].second;
            cur2 += a[i].second;
        }

        return ans;
    }
};