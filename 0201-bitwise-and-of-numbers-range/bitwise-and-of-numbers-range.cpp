class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        bitset<32> L = left, R = right;
        int ans = 0;
        for(int i = 31; i >= 0; i--)
        {
            if(L[i] && R[i])    
            {
                ans += (1 << i);
            }
            else if (R[i])
            {
                break;
            }
        }
        return ans;
    }
};