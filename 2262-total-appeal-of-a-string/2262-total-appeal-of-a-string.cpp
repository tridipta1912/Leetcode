class Solution {
public:
    long long appealSum(string s) {
        vector<vector<int>> pos(26);
        for(int i = 0; i < 26; i++) pos[i].push_back(-1);
        for(int i = 0; i < s.length(); i++) pos[s[i] - 'a'].push_back(i);
        for(int i = 0; i < 26; i++) pos[i].push_back(s.length());

        long long ans = 13 * (s.length()) * (s.length() + 1);
        for(int i = 0; i < 26; i++)
        {
            for(int j = 1; j < pos[i].size(); j++)
            {
                int l = pos[i][j - 1];
                int r = pos[i][j];
                long long len = r - l - 1;
                ans -= ((len * (len + 1)) / 2);
            }
        }
        return ans;
    }
};