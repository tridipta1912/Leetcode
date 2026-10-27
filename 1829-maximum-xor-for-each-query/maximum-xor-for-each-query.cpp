class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) 
    {
        int xorr = 0;
        for(auto val: nums)
        {
            xorr ^= val;
        }   
        
        vector<int> ans;
        int n = nums.size();

        int mask = (1 << maximumBit) - 1;
        for(int i = n - 1; i >= 0; i--)
        {
            int k = ~xorr & mask;
            ans.push_back(k);
            xorr ^= nums[i];
        }
        return ans;
    }
};