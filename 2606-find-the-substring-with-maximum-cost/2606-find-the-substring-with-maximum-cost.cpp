class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        using ll = int;
        vector<ll> val(26);
        iota(val.begin(), val.end(), 1);
        for(ll i = 0; i < chars.length(); i++)  val[chars[i] - 'a'] = vals[i];
        
        ll ans = 0, cur = 0;
        for(auto x : s)
        {
            cur += val[x - 'a'];
            cur = max(cur, 0);
            ans = max(ans, cur);
        }
        return ans;
    }
};