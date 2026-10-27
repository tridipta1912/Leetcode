class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int ans = 0, cur = 0;
        vector<int> last(26, 0);
        int lst = 1e9;
        for(int i = 0; i < s.length(); i++)
        {
            if(lst == 1e9)  cur = 1;
            else if ((lst + 1) % 26 == s[i] - 'a')   cur++;
            else    cur = 1;
            lst = s[i] - 'a';
            ans += max(cur - last[s[i] - 'a'], 0);
            last[s[i] - 'a'] = max(last[s[i] - 'a'], cur);
        }
        return ans;
    }
};