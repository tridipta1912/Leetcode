class Solution {
public:
    string longestPalindrome(string s) 
    {
        int ans = 0;
        int n = s.length();
        string str = "";
        for(int i = 0;i<s.length();i++)
        {
            //even
            string str_even = "";
            int L = i;
            int R = i + 1;
            while(L>=0 && R<(n) && s[L] == s[R])
            {
                str_even += s[R];
                L--;
                R++;
            }

            if(2 * str_even.length() > str.length())
            {
                string replica = str_even;
                reverse(replica.begin(),replica.end());
                replica += str_even;
                str = replica;
            }
            //odd
                string str_odd = "";
                L = i - 1;
                R = i + 1;
                while(L>=0 && R<(n) && s[L] == s[R])
                {
                    str_odd += s[R];
                    L--;
                    R++;
                }
                cout << str_odd << endl;
                if(2 * str_odd.length() + 1 > str.size())
                {
                    string replica = str_odd;
                    reverse(replica.begin(),replica.end());
                    replica += s[i];
                    replica += str_odd;
                    str = replica;
                }
        }
        return str;
    }
};