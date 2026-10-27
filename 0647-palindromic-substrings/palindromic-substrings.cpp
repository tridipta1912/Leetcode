class Solution {
public:
    int countSubstrings(string s) 
    {
        int n = s.length();
        int c = 0;
        for(int i = 0;i<n;i++)
        {
            c++;
            int L = i - 1;
            int R = i + 1;
            while(L>=0 && R<=(n-1))
            {
                if(s[L] == s[R])
                {
                    c++;
                    L--;
                    R++;
                }
                else
                {
                    break;
                }
            }
            L = i - 1;
            R = i;
            while(L>=0 && R<=(n-1))
            {
                if(s[L] == s[R])
                {
                    c++;
                    L--;
                    R++;
                }
                else
                {
                    break;
                }
            }
        }
        return c;
    }
};