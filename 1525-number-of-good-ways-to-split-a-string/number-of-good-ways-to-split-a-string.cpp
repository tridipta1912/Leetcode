class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
       vector<int> freq(26), pref(s.length()), suff(s.length());
       for(int i = 0; i < n; i++)
        {
            if(freq[s[i] - 'a'] == 0) pref[i]++;
            freq[s[i] - 'a']++;
            if(i > 0)   pref[i] += pref[i - 1];
        }
        freq.assign(26, 0);
        for(int i = n - 1; i >= 0; i--)
        {
            if(freq[s[i] - 'a'] == 0) suff[i]++;
            freq[s[i] - 'a']++;
            if(i + 1 < n)   suff[i] += suff[i + 1];
        }
        int ans = 0;
        for(int i = 1; i < n; i++)  ans += (pref[i - 1] == suff[i]);
        return ans;
    }
};