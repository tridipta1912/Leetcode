class Solution {
public:
    int countPrimes(int n) 
    {
        if(n <= 2)  return 0;

        n--;
        vector<bool> isPrime(n + 1, true);
        int count = 0;

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i <= n; i++)
        {
            if(isPrime[i])
            {
                count++;
                for(int j = 2 * i; j <= n; j+=i)    isPrime[j] = false;
            }
        }

        return count;
    }
};