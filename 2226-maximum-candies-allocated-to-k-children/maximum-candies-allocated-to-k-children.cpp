class Solution {
public:
#define ll long long
    bool predicate(vector<int>& candies, long long k, long long c)
    {
        ll x  = 0;
        for(auto &nums:candies)    x+=(nums/c);

        return (x>=k);
    }
    ll maximumCandies(vector<int>& candies, long long k) 
    {
        ll L = 1;
        ll R = 1e9;
        ll ans = 0;
        while(L<=R)
        {
            ll M = L + (R-L)/2;
            if(predicate(candies,k,M))
            {
                ans = M;
                L = M + 1;
            }
            else
            {
                R = M - 1;
            }
        }
        return ans;
    }
};