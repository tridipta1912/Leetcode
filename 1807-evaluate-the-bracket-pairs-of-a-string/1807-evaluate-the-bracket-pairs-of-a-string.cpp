class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string cur = "", ans = "";
        unordered_map<string, int> mp;
        for(int i = 0; i < knowledge.size(); i++) mp[knowledge[i][0]] = i;
        bool is_open = false;
        for(auto &x : s)
        {
            if(x == '(')    is_open = true;
            else if(x == ')')   
            {
                ans += ((mp.find(cur) == mp.end()) ? "?" : knowledge[mp[cur]][1]);
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