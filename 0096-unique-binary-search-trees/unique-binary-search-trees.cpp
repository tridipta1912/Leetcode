class Solution {
public:
    int numTrees(int n) {
        long long pro = 1LL;
        for (int i = 1; i <= n; i++) {
            pro = pro * (n + i) / i;
        }
        return (int)(pro / (n + 1));
    }
};
