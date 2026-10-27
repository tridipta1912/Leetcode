class Solution {
public:
    bool closeStrings(string word1, string word2) {
        using ll = long long;
        vector<ll> freq(26), freq1(26);
        for(auto x : word1) freq[x - 'a']++;
        for(auto x : word2) freq1[x - 'a']++;
        for(ll i = 0; i < 26; i++)  
        {
            if((freq[i] && !freq1[i]) || (!freq[i] && freq1[i]))
            {
                return false;
            }
        }
        sort(freq.begin(), freq.end());
        sort(freq1.begin(), freq1.end());
        for(ll i = 0; i < 26; i++)  if(freq[i] != freq1[i]) return false;
        return true;
    }
};