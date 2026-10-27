class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        using ll = long long;
        
        ll g = 0;
        for(auto x : numsDivide) g = gcd(x, g);
        
        ll minn = 1e18;
        for(auto x : nums) if(g % x == 0) minn = min(minn, (ll)x);
        if(minn == 1e18)    return -1;
        
        ll cnt = 0;
        for(auto x : nums)  cnt += (x < minn);
        return cnt;
    }
};