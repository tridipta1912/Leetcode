class Solution {
public:
    int minMoves(vector<int>& nums) {
        int tot = 0, maxx = *max_element(nums.begin(), nums.end());
        for(auto &x : nums) tot += (maxx - x);
        return tot;
    }
};