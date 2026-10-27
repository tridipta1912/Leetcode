class Solution {
public:
    bool checkPartitioning(string s) {
        using ll = int;
        ll n = s.length();
        vector<set<ll>> poss(n);
        vector<bool> pref(n), suff(n);
        for(int i = 0; i < n; i++)
        {
            ll L = i;
            ll R = i;
            while(L >= 0 && R < n && s[L] == s[R])
            {
                if(L == 0)  pref[R] = true;
                if(R == n - 1)  suff[L] = true;
                poss[R].insert(L);
                L--;
                R++;
            }
            L = i;
            R = i + 1;
            while(L >= 0 && R < n && s[L] == s[R])
            {
                if(L == 0)  pref[R] = true;
                if(R == n - 1)  suff[L] = true;
                poss[R].insert(L);
                L--;
                R++;
            }
        }
        
        bool b = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 2; j < n; j++)
            {
                if(pref[i] && suff[j] && poss[j - 1].count(i + 1))  b = true;
            }
        }

        return b;
    }
};