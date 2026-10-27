class Solution {
public:
    long long splitArray(vector<int>& nums) {
        using ll = long long;
        ll n = nums.size();
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i < n; i++)
        {
            if(isPrime[i])
            {
                for(int j = 2 * i; j < n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        ll ans1 = 0, ans2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(isPrime[i])  ans1 += nums[i];
            else            ans2 += nums[i];
        }
        return (ll)(abs(ans1 - ans2));
    }
};