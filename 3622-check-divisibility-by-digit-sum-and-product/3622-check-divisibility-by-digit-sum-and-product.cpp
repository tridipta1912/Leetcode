class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, pro = 1, val = n;
        while(n)    
        {
            int d = n % 10; 
            sum += d;
            pro *= d;
            n /= 10;
        }
        return ((val % (sum + pro)) == 0);
    }
};