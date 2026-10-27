class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for(int i = shifts.size() - 2; i >= 0; i--) shifts[i] += shifts[i + 1], shifts[i] %= 26;
        for(int i = 0; i < s.length(); i++) s[i] = char((s[i] - 'a' + shifts[i]) % 26 + 'a');
        return s;
    }
};