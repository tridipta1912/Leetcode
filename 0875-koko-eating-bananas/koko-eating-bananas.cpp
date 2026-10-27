class Solution {
public:
    bool predicate(vector<int>& x, int h, int k)
    {
        long long sum = 0;
        for(auto &nums:x)
        {
            sum+=ceil(nums/double(k));
        }
        return (sum<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int L = 1, R = 1e9, ans;
        while(L<=R)
        {
            int M = L + (R-L)/2;
            if(predicate(piles,h,M))
            {
                ans = M;
                R = M - 1;
            }
            else
            {
                L = M + 1;
            }
        }
        return ans;
    }  
};