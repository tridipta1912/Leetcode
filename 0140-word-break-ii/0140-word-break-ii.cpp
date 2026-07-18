class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<vector<string>> dp(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < wordDict.size(); j++)
            {
                if(i + wordDict[j].length() > n)   continue;
                string a = s.substr(i, wordDict[j].length());
                if(a == wordDict[j])    
                {
                    if(i == 0)  dp[wordDict[j].length() - 1].push_back(wordDict[j]);
                    else
                    {
                        for(auto x : dp[i - 1])
                        {
                            string s = x;
                            s += ' ';
                            s += wordDict[j];
                            dp[i + wordDict[j].length() - 1].push_back(s);
                        }
                    }
                }
            }
        }

        return dp.back();
    }
};