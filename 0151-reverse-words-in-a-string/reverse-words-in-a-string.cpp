class Solution {
public:
    string reverseWords(string s) {
        string x = "", cur = "";
        int n = s.length();

        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] != ' ')     cur += s[i];
            else                
            {
                reverse(cur.begin(), cur.end());
                if(!x.empty() && x.back() != ' ') x += ' ';
                x += cur;
                cur = "";
            }
        }
        reverse(cur.begin(), cur.end());
        if(!cur.empty() && !x.empty() && x.back() != ' ') x += ' ';
        x += cur;
        while(x.back() == ' ')  x.pop_back();
        return x;       
    }
};