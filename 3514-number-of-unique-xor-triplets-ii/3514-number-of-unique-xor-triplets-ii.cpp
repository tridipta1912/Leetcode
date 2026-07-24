class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> poss;
        for(auto x : nums)
        {
            for(auto y : nums)  poss.insert((x ^ y));
        }
        unordered_set<int> ans;
        for(auto x : poss)
        {
            for(auto y : nums)  ans.insert((x ^ y));
        }
        return ans.size();
    }
};