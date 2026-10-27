class Solution {
public:
    int numDecodings(string s) {
        using ll = long long;
        vector<ll> dp(s.length() + 1);
        dp[0] = 1;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != '0') dp[i + 1] += dp[i];
            if(i > 0)
            {
                string str = "";
                str += s[i - 1];
                str += s[i];
                int num = stoi(str);
                if(num >= 10 && num <= 26) dp[i + 1] += dp[i - 1];
            }
        }

        return (int)dp.back();
    }
};