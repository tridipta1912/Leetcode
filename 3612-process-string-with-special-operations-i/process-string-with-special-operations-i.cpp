class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(auto c : s)
            {
                if(c >= 'a' && c <= 'z')
                {
                    ans += c;
                }
                else if(c == '*')
                {
                    if(!ans.empty())
                    {
                        ans.pop_back();
                    }
                }
                else if (c == '#')ans += ans;
                else reverse(ans.begin(), ans.end());
            }
        return ans;
    }
};