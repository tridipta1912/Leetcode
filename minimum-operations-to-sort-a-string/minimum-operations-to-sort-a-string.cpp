class Solution {
public:
    int minOperations(string s) {
        string t = s;
        sort(t.begin(), t.end());
        if(s == t)  return 0;
        
        if(s.length() == 2) return -1;

        if(s.front() == t.front())  return 1;
        if(s.back() == t.back())    return 1;

        vector<int> freq(26);
        for(auto x : s) freq[x - 'a']++;
        
        if((s.back() == t.front()) && (s.front() == t.back()) && freq[t[0] - 'a'] == 1 && freq[s[0] - 'a'] == 1)    return 3;
        return 2;
    }
};