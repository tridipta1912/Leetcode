class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 1e18;
        ans = ((long long)cost1 * need1 + (long long)cost2 * need2);
        long long min_need = min(need1, need2);
        ans = min(ans, costBoth * min_need + cost1 * (need1 - min_need) + cost2 * (need2 - min_need));
        ans = min(ans, (long long)costBoth * max(need1, need2));
        return ans;
    }
};