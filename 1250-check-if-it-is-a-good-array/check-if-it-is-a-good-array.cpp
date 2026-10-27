class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = 0;
        for(auto val : nums)    g = __gcd(g, val);
        return (g == 1);
    }
};