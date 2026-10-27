class Solution 
{
public:
    int repeatedStringMatch(string a, string b) 
    {
        using ll = long long;
        const int p = 31;
        const int MOD = 1e9 + 7;

        string pr = a;
        while (a.length() < b.length()) 
        {
            a += pr;
        }

        int sz = b.length();
        int maxx = a.length() + pr.length(); 
        vector<ll> powp(maxx + 1);
        powp[0] = 1;
        for (int i = 1; i <= maxx; i++) 
        {
            powp[i] = (powp[i - 1] * p) % MOD;
        }

        auto check = [&](string &a_str, string &b_str)
        {
            int sz = b_str.length();
            ll hash2 = 0;
            for (int i = 0; i < sz; i++) 
            {
                hash2 = (hash2 + (b_str[i] - 'a' + 1) * powp[sz - i - 1]) % MOD;
            }

            ll hash1 = 0;
            for (int i = 0; i < sz; i++) 
            {
                hash1 = (hash1 + (a_str[i] - 'a' + 1) * powp[sz - i - 1]) % MOD;
            }

            if (hash1 == hash2 && a_str.substr(0, sz) == b_str) 
                return true;

            for (int i = sz; i < a_str.length(); i++) 
            {
                hash1 = (hash1 - (a_str[i - sz] - 'a' + 1) * powp[sz - 1]) % MOD;
                if (hash1 < 0) hash1 += MOD;
                hash1 = (hash1 * p + (a_str[i] - 'a' + 1)) % MOD;

                if (hash1 == hash2 && a_str.substr(i - sz + 1, sz) == b_str) 
                    return true;
            }

            return false;
        };

        if (check(a, b)) 
        {
            return (a.length() / pr.length());
        }

        a += pr;
        if (check(a, b)) 
        {
            return (a.length() / pr.length());
        }

        return -1;
    }
};
