class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26);
        for(auto c : s) a[c - 'a']++;
        
        for(auto c : t)
        {
            if(!a[c - 'a']) return 0;
            a[c - 'a']--;
        }

        return (accumulate(a.begin(), a.end(), 0) == 0);
    }
};