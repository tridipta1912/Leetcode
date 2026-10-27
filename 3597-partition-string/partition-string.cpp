class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> pres;
        string cur = "";
        vector<string> ans;
        for(int i = 0; i < s.length(); i++)
            {
                cur += s[i];
                    if(pres.count(cur))continue;
                ans.push_back(cur);
                pres.insert(cur);
                cur = "";
            }
        return ans;
    }
};