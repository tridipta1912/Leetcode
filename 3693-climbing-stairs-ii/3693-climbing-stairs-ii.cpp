class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        using ll = int;
        constexpr ll INF = 2e9;
        array<ll, 3> cur = {INF, INF, 0};
        for(ll i = 0; i < n; i++)
        {
            array<ll, 3> ncur;
            ncur[0] = cur[1];
            ncur[1] = cur[2];
            ncur[2] = costs[i] + min({cur[0] + 9, cur[1] + 4, cur[2] + 1});
            swap(ncur, cur);
        }
        return cur[2];
    }
};