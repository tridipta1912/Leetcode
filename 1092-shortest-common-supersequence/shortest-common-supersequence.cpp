class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(str1[i - 1] == str2[j - 1])    
                {
                    dp[i][j] = 1;
                    dp[i][j] += dp[i - 1][j - 1];
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }

        int L = n, R = m;
        string s = "";
        while(L && R)
        {
            if(dp[L][R] == dp[L - 1][R - 1] + 1 && str1[L - 1] == str2[R - 1])
            {
                s += str1[L - 1];
                L--, R--;
            }
            else if (dp[L - 1][R] > dp[L][R - 1])
            {
                L--;
            }
            else
            {
                R--;
            }
        }

        reverse(s.begin(), s.end());
        
        string ans = "";
        int ptr1 = 0, ptr2 = 0;
        for(int i = 0; i < s.length(); i++)
        {
            while(str1[ptr1] != s[i])   ans += str1[ptr1++];
            while(str2[ptr2] != s[i])   ans += str2[ptr2++];
            ans += s[i];
            ptr1++, ptr2++;
        }
        while(ptr1 != str1.size())  ans += str1[ptr1++];
        while(ptr2 != str2.size())  ans += str2[ptr2++];

        return ans;
    }
};