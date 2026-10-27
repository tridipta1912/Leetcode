// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1;
        int R = n;
        int ans;
        while(L <= R)
        {
            int M = L + (R - L)/2;
            if(isBadVersion(M)) ans = M, R = M - 1;
            else                L = M + 1;
        }
        return ans;
    }
};