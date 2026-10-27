class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 31; i++)
        {
            int k = 0;
            for(auto &j : nums)
            {
                k += (((j >> i) & 1));
            }
            ans += (k) * (nums.size() - k);
        }

        return ans;
    }
};