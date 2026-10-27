class Solution {
public:
    string convert(string s, int numRows) 
    {
        vector<string> ans(numRows, "");
        int n = s.length();
        bool up = true;
        int ind = 0;
        for(int i = 0 ; i<s.length() ; i++)
        {
            ans[ind] += s[i];
            if(ind == 0)    up = true;
            if(ind == numRows - 1)    up = false;

            if(up)  ind++;
            else    ind--;

            ind = max(ind, 0);
            ind = min(ind, (numRows - 1));
        }

        string answer = "";
        for(auto &str: ans) answer += str;
        return answer;
    }
};