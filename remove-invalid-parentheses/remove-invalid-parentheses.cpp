class Solution
{
public:
    vector<string> removeInvalidParentheses(string s)
    {
        using ll = long long;
        ll n = s.size();
        vector<ll> pos;

        for(ll i = 0; i < n; i++)
        {
            if(s[i] == '(' || s[i] == ')')
            {
                pos.push_back(i);
            }
        }

        ll m = pos.size();
        ll left = 0, right = 0;

        for(char c : s)
        {
            if(c == '(')
            {
                left++;
            }
            else if(c == ')')
            {
                if(left)
                {
                    left--;
                }
                else
                {
                    right++;
                }
            }
        }

        ll need = left + right;
        ll keep = m - need;

        vector<string> ans;
        unordered_set<string> seen;

        auto valid = [&](ll mask) -> bool
        {
            ll bal = 0;
            ll p = 0;

            for(ll i = 0; i < n; i++)
            {
                if(s[i] == '(' || s[i] == ')')
                {
                    if(mask & (1 << p))
                    {
                        p++;
                        continue;
                    }

                    p++;
                }

                if(s[i] == '(')
                {
                    bal++;
                }
                else if(s[i] == ')')
                {
                    if(--bal < 0)
                    {
                        return false;
                    }
                }
            }

            return bal == 0;
        };

        auto build = [&](ll mask)
        {
            string t;
            t.reserve(n - need);

            ll p = 0;

            for(ll i = 0; i < n; i++)
            {
                if(s[i] == '(' || s[i] == ')')
                {
                    if(mask & (1 << p))
                    {
                        p++;
                        continue;
                    }

                    p++;
                }

                t.push_back(s[i]);
            }

            return t;
        };

        ll limit = 1 << m;

        for(ll mask = 0; mask < limit; mask++)
        {
            if(__builtin_popcount((unsigned)mask) != need)
            {
                continue;
            }

            if(!valid(mask))
            {
                continue;
            }

            string t = build(mask);

            if(seen.insert(t).second)
            {
                ans.push_back(move(t));
            }
        }

        return ans;
    }
};