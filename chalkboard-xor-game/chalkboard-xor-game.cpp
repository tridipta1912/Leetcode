class Solution {
public:
    bool xorGame(vector<int>& nums) {
        using ll = int;
        ll n = nums.size();
        ll xorr = 0;
        for(auto &x : nums)     xorr ^= x;
        return (((n & 1) == 0) || (xorr == 0));
    }
};