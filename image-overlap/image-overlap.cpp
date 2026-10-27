class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        using ll = int;
        vector<array<ll, 2>> pos;
        for(ll i = 0; i < img1.size(); i++)
        {
            for(ll j = 0; j < img1[0].size(); j++)
            {
                if(img1[i][j])   pos.push_back({i, j});
            }
        }

        unordered_map<ll, ll> st;

        ll ans = 0;
        ll n = img1[0].size();
        for(ll i = 0; i < img2.size(); i++)
        {
            for(ll j = 0; j < img2[0].size(); j++)
            {
                if(img2[i][j])
                {
                    for(auto [x, y] : pos)    st[2 * n * (x - i) + (y - j)]++, ans = max(ans, st[2 * n * (x - i) + (y - j)]);
                }
            }
        }

        return ans;
    }
};