class Solution {
public:
    string countAndSay(int n) 
    {
        string s = "1";
        for(int i = 0; i < (n - 1); i++)
        {
            string n_s = "";
            int L = 0, count = 0;
            for(int j = 0; j < s.length(); j++)
            {
                if(s[L] == s[j])    count++;
                else
                {
                    n_s += to_string(count);
                    n_s += s[L];
                    L = j;
                    count = 1;
                }
            }
            n_s += to_string(count);
            n_s += s[L];
            s.swap(n_s);
        }
        return s;
    }
};