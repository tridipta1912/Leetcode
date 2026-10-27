class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        using ll = long long;
        vector<ll> r;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '1') r.push_back(i);
        }
        pair<ll, string> ans = {(ll)1e18, ""};
        for(ll i = 0; i + k - 1 < r.size(); i++)
        {
            string x = "";
            for(ll j = r[i]; j <= r[i + k - 1]; j++)    x += s[j];
            ans = min(ans, {(ll)x.length(), x});
        }
        return ans.second;
    }
};