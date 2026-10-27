class Solution {
public:
    long long minEnd(int n, int x) {
        long long val = x;
        long long tt = (n - 1);
        for(int i = 0; i < 63; i++)
        {
            if((x & (1LL << i)) == 0)
            {
                if((tt & 1LL))    val += (1LL << i);
                tt /= 2;
            }
            if(x == 0)  break;
        }
        return val;
    }
};