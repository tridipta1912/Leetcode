class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> poss(2048);
        for(auto x : nums)
        {
            for(auto y : nums)  poss[(x ^ y)] = 1;
        }
        int ans = 0;
        for(int i = 0; i < 2048; i++)
        {
            bool ch = false;
            for(auto x : nums)  if(poss[(i ^ x)])   ch = true;
            ans += ch;
        }
        return ans;
    }
};