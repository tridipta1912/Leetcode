class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s = "";
        sort(nums.begin(), nums.end(), [&](int x, int y)
        {
            string a = to_string(x);
            string b = to_string(y);
            return (a + b > b + a);
        });
        for(auto x : nums)  s += to_string(x);
        while(s.length() > 1 && s[0] == '0')    s.erase(s.begin());
        return s;
    }
};