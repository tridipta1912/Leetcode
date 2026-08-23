class Solution {
public:
    bool isSubsequence(string s, string t) {
        using ll = long long;
        ll cur = 0;
        for(ll i = 0; i < t.length(); i++)
        {
            if(cur == s.length())   return true;
            if(s[cur] == t[i])  cur++;
        }
        return (cur == s.length());
    }
};