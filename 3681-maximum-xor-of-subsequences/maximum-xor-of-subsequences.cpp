class Solution {
public:
    int maxXorSubsequences(vector<int>& a) {
         const int BITS = 32; 
        vector<int> basis(BITS, 0);

        for (int x : a) {
            for (int b = BITS - 1; b >= 0; b--) {
                if (!(x & (1 << b))) continue;
                if (!basis[b]) {
                    basis[b] = x;
                    break;
                }
                x ^= basis[b];
            }
        }

        int ans = 0;
        for (int b = BITS - 1; b >= 0; b--) {
            ans = max(ans, ans ^ basis[b]);
        }
        return ans;
    }
};