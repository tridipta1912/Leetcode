class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        using ll = int;
        vector<array<ll, 2>> pos(26, {-1, -1});
        vector<ll> freq(26);
        for(ll i = 0; i < s.length(); i++)
        {
            if(pos[s[i] - 'a'][0] == -1)    pos[s[i] - 'a'][0] = i;
            pos[s[i] - 'a'][1] = i;
            freq[s[i] - 'a']++;
        }

        vector<array<ll, 2>> val;
        for(ll i = 0; i < 26; i++)
        {
            if(pos[i][0] != -1)
            {
                bool b = true;
                ll maxx = pos[i][1];
                for(ll j = pos[i][0]; j <= maxx; j++)
                {
                    if(pos[s[j] - 'a'][0] < pos[i][0])  
                    {
                        b = false;
                        break;
                    }
                    maxx = max(maxx, pos[s[j] - 'a'][1]);
                }
                if(b) val.push_back({pos[i][0], maxx});
            }
        }

        vector<string> ans;

        sort(val.begin(), val.end(), [&](array<ll, 2> &a, array<ll, 2> &b)
        {
            if(a[1] == b[1])    return (a[0] < b[0]);
            return (a[1] < b[1]);
        });

        ll lst = -1;
        for(auto [x, y] : val)
        {
            if(x > lst)
            {
                ans.push_back(s.substr(x, y - x + 1));
                lst = y;
            }
        }
        return ans;
    }
};