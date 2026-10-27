class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> freq (26, 0);
        for(auto c: s)  freq[c - 'a']++;

        int cnt = 0;
        for(auto x : freq)  cnt += (x % 2);

        return (cnt <= k && s.length() >= k);
    }
};