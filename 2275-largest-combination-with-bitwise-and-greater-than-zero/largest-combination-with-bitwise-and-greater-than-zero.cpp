class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxx = 0;
        int count = 0;
        for(int i = 0; i < 30; i++)
        {
            for(auto nums: candidates)
            {
                count += (((1 << i) & nums) != 0);
            }
            maxx = max(maxx, count);
            count = 0;
        }
        return maxx;
    }
};