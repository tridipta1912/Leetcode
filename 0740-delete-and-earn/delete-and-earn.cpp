class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mp;
        for(auto x : nums)  mp[x]++;
        int maxx = 0, last = 0, last1 = 0, ans = 0;
        for(auto [x, y] : mp)
        {
            if(x - last1 > 1)   maxx = max(maxx, last);
            int val = x * y + maxx;
            maxx = max(maxx, last);
            last = val;
            last1 = x;
            ans = max(ans, val);
        }
        return ans;
    }
};