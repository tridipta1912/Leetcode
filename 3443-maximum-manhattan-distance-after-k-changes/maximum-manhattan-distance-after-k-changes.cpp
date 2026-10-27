class Solution {
public:
    int maxDistance(string s, int k) {
        vector<int> a(2);
        vector<int> b(2);

        int ans = 0;
        
        for(auto c : s)
        {
            if(c == 'N')    a[0]++;
            else if(c == 'S')   a[1]++;

            if(c == 'W')    b[0]++;
            else if(c == 'E')   b[1]++;

            int change = min({a[0], a[1], k});
            change += min({b[0], b[1], k - change});

            ans = max(ans, abs(a[0] - a[1]) + abs(b[0] - b[1]) + 2 * change);
        }

        return ans;
    }
};