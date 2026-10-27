class Solution {
public:
    int minInsertions(string s) {
        using ll = int;
        ll ans = 0, cur = 0;
        for(ll i = 0; i < s.length(); i++)
        {
            if(s[i] == '(') cur++;
            else if (s[i] == ')')
            {
                if(i + 1 < s.length() && s[i + 1] == ')')
                {
                    if(cur) cur--;
                    else
                    {
                        ans++;
                    }
                    i += 1;
                }
                else
                {
                    if(cur) ans++, cur--;
                    else
                    {
                        ans += 2;
                    }
                }
            }
        }
        ans += (2 * cur);
        return ans;
    }
};