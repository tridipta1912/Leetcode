class Solution {
public:
    int minMoves(vector<int>& nums) {
        int tot = 0, maxx = 0;
        for(auto &x : nums) tot += x, maxx = max(maxx, x);
        return ((nums.size() * maxx) - tot);
    }
};