class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for(auto nums : points)
        {
            map<array<int, 2>, int> mp;
            for(auto nums1 : points)
            {
                int dx = nums[0] - nums1[0];
                int dy = nums[1] - nums1[1];
                int g = __gcd(abs(dx), abs(dy));
                if(g == 0)   continue;
                dx /= g, dy /= g;
               //  cout << dx << ' ' << dy << endl;
                mp[{dx, dy}]++;
                ans = max(ans, mp[{dx, dy}] + 1);
            }
        }
        return ans;
    }
};