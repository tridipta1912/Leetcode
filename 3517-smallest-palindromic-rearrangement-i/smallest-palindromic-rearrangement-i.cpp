class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> v(26);
        for(int i = 0; i < s.length(); i++) v[s[i] - 'a']++;

        string ans = "";
        char r = '\n';
        for(int i = 0; i < 26; i++)
        {
            if(v[i] % 2) r = char(i + 'a'), v[i]--;
            for(int j = 0; j < v[i]; j += 2)    ans += char(i + 'a');
        }
        string rev = ans;
        reverse(rev.begin(), rev.end());
        if(r != '\n')   ans += r;
        ans += rev;
        return ans;
    }
};