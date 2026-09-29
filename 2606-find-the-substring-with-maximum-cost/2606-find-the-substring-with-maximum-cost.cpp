class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        using ll = int;
        vector<ll> val(26);
        iota(val.begin(), val.end(), 1);
        for(ll i = 0; i < chars.length(); i++)  val[chars[i] - 'a'] = vals[i];
        vector<ll> arr;
        for(auto x : s) arr.push_back(val[x - 'a']);

        ll ans = 0, cur = 0;
        for(auto x : arr)
        {
            cur += x;
            cur = max(cur, 0);
            ans = max(ans, cur);
        }
        return ans;
    }
};