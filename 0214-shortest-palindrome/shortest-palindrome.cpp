class Solution {
public:
    string shortestPalindrome(string s) {
        using ll = long long;
        if(s.length() < 2)  return s;
        string s2 = s;
        reverse(s2.begin(), s2.end());
        string s1 = s;
        s1 += '$';
        s1 += s2;

        ll n = s1.length();
        vector<int> pi(n);
        for(int i = 1; i < n; i++)
        {
            int j = pi[i - 1];
            while(j && s1[j] != s1[i]) j = pi[j - 1];
            if(s1[j] == s1[i])    j++;
            pi[i] = j;
        }
        string add = "";
        ll to = s.length() - pi[n - 1];
        for(int i = s.length() - 1; i >= (s.length() - to); i--)    add += s[i];
        add += s;
        return add;
    }
};