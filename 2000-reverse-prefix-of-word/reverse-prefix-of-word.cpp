class Solution {
public:
    string reversePrefix(string word, char ch)
    {
        string ans = "";
        int L = 0;
        while(L<word.length())
        {
            ans+=word[L];
            if(word[L] == ch)   break;
            L++;
        }
        if(L!=word.length())    reverse(ans.begin(),ans.end());
        L++;
        while(L<word.length())
        {
            ans+=word[L];
            L++;
        }
        return ans;
    }
};