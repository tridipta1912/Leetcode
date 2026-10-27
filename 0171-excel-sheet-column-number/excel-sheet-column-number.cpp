class Solution {
public:
    int titleToNumber(string columnTitle) {
        //CAB = BAC = 2 + (1 * 26) + (3 * 26^2)
        using ll = long long;
        ll mult = 1, ans = 0;
        reverse(columnTitle.begin(), columnTitle.end());
        for(auto c : columnTitle)
        {
            ans += (c - 'A' + 1) * mult;
            mult *= 26;
        }
        return (int)ans;
    }
};