class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for(int i = 0; i < n; i++)  ans += abs(2 * i + 1 - n);
        ans /= 2;
        return ans;
    }
};