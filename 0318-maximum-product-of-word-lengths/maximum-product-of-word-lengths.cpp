class Solution {
public:
    int maxProduct(vector<string>& words) {
        using ll = long long;
        ll n = words.size();
        vector<ll> mask(n);
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < words[i].length(); j++)   mask[i] |= (1LL << (words[i][j] - 'a'));
        }
        ll ans = 0;
        for(ll i = 0; i < n; i++)
        {
            for(ll j = i + 1; j < n; j++)   
            {
                ll k = words[i].length() * words[j].length();
                if(!(mask[i] & mask[j]))    ans = max(ans, k);
            }
        }

        return ans;
    }
};