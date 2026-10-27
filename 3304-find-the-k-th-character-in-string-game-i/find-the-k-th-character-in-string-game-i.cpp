class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(s.length() < k)
        {
            string ns = "";
            for(auto c : s) ns += char((c - 'a' + 1) % 26 + 'a');
            s += ns;
        }
        return s[k - 1];
    }
};