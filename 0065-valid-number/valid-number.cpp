class Solution {
public:
    bool isNumber(string s) 
    {
        using ll = long long;
        ll n = s.size();
        bool chk1 = false, ans = false, chk2 = false;
        for(int i = 0; i < n; i++)
        {
            if(s[i] >= '0' && s[i] <= '9') ans = true;
            else if(s[i] == '+' || s[i] == '-')
            {
                if(i > 0 && (s[i - 1] != 'e' && s[i - 1] != 'E')) return false;
            }
            else if(s[i] == 'e' || s[i] == 'E')
            {
                if(!ans)    return false;
                if(chk2)    return false;
                chk2 = true;
                ans = false;
            }
            else if(s[i] == '.')
            {
                if(chk1 || chk2) return false;
                chk1 = true;
            }
            else 
            {
                return false;
            }
        }
        return ans;
    }
};