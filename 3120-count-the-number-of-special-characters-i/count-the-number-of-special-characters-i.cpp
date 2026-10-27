class Solution {
public:
    int numberOfSpecialChars(string word) 
    {
        map<int,int> mp;
        for(auto c:word)
        {
            mp[c]++;
        }
        int count = 0;
        for(char c = 'A'; c<='Z'; c++)
        {
            if(mp[c] && mp[c|' '])  count++;
        }
        return count;
    }
};