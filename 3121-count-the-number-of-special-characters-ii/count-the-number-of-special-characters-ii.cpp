class Solution {
public:
    int numberOfSpecialChars(string s) 
    {
        unordered_map<int,int> mp;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]>='a')
            {
                mp[s[i]] = (i+1);
            }
            else if(!mp[s[i]])
            {
                mp[s[i]] = (i+1);
            }
        }

        int count = 0;
        for(char c = 'A';c <= 'Z';c++)
        {
            if(mp[c] && mp[c|' '])
            {
                if(mp[c|' ']<mp[c]) count+=1;
            }
        }
        return count;
    }
};