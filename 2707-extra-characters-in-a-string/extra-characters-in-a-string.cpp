class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        map<string,bool> found;
        for(auto str: dictionary)   found[str] = true;

        vector<int> dp(s.length(),1e9);   

        for(int i = 0; i<s.length(); i++)
        {
            for(int j = 0; j<=i; j++)
            {
                if(found[s.substr(j,(i - j + 1))])  
                {
                    if(j == 0)  dp[i] = 0;
                    else    dp[i] = min(dp[i], dp[j - 1]);
                }
                else
                {
                    if (j == 0) dp[i] = min(dp[i], i + 1);
                    else dp[i] = min(dp[i], dp[j - 1] + (i - j + 1));
                }
            }
        }
        return dp.back();
    }
};