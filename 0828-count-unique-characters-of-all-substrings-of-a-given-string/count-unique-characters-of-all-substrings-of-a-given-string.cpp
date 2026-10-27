class Solution {
public:
    int uniqueLetterString(string s) {
        using ll = int;
        vector<ll> last(26, -1);
        ll n = s.length();
        vector<ll> left(n), right(n);
        for(ll i = 0; i < n; i++)
        {
            ll c = s[i] - 'A';
            if(last[c] != -1)   left[i] = last[c];
            else                left[i] = -1;
            last[c] = i;
        }
        last.assign(26, -1);
        for(ll i = n - 1; i >= 0; i--)
        {
            ll c = s[i] - 'A';
            if(last[c] != -1)   right[i] = last[c];
            else                right[i] = n;
            last[c] = i;
        }
        ll ans = 0;
        for(ll i = 0; i < n; i++)   
        {
            ans += (right[i] - i) * (i - left[i]);
        }
        return ans;
    }
};