class Solution {
public:
    int strongPasswordChecker(string password) {
        string s = password;
        int n = s.length(), l = 0, u = 0, d = 0;
        for (char c : s) 
        {
            if (islower(c)) l = 1;
            if (isupper(c)) u = 1;
            if (isdigit(c)) d = 1;
        }

        int m = 3 - (l + u + d), r = 0, o = 0, t = 0;
        for (int i = 2; i < n; ++i) 
        {
            if (s[i] == s[i - 1] && s[i] == s[i - 2]) 
            {
                int len = 2;
                while (i < n && s[i] == s[i - 1]) ++i, ++len;
                r += len / 3;
                if (len % 3 == 0) ++o;
                else if (len % 3 == 1) ++t;
            }
        }

        int ans = 0;

        if (n < 6) 
        {
            ans = max(6 - n, m);
        } 
        else if (n <= 20) 
        {
            ans =  max(r, m);
        } 
        else 
        {
            int x = n - 20, y = x;
            r -= min(x, o);
            x -= min(x, o);
            r -= min(x, 2 * t) / 2;
            x -= min(x, 2 * t);
            r -= x / 3;
            ans = y + max(r, m);
        }

        return ans;
    }
};