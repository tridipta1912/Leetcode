class Solution {
public:
    int reverse(int x) {
        int num = abs(x);
        long int n=0;
        while(num>0)
        {
            int d=num%10;
            num = num / 10;
            n = (n*10*1LL)+d;
        }
        if(x<0)     n=n*(-1);

        if(n>INT_MAX || n<INT_MIN)     return 0;
        return n;
    }
};