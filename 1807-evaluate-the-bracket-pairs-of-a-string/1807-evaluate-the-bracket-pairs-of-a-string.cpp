class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string cur = "", ans = "";
        map<string, string> mp;
        for(auto &x : knowledge) mp[x[0]] = x[1];
        bool is_open = false;
        for(auto &x : s)
        {
            if(x == '(')    is_open = true;
            else if(x == ')')   
            {
                ans += ((mp.find(cur) == mp.end()) ? "?" : mp[cur]);
                is_open = false;
                cur = "";
            }
            else
            {
                if(is_open) cur += x;
                else
                {
                    ans += x;
                }
            }
        }
        return ans;
    }
};