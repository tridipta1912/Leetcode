class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto v : nums)  mp[v]++;

        int ans = 0;
        for(auto [a, b] : mp)
        {
            int tt = b;
            if(!mp.count(a + 1)) continue;
            tt += mp[a + 1];
            ans = max(ans, tt);
        }
        return ans;
    }
};