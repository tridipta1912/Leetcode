class Solution {
public:
    int tribonacci(int n) 
    {
        long long a = 0, b = 1, c = 1;
        if(n <= 1)  return n;
        if(n == 2)  return 1;

        long long x = 0;
        n-=2;
        for(int i = 1;i<=n;i++)
        {
            x = a + b + c;
            a = b;
            b = c;
            c = x;
        }
        return x;
    }
};