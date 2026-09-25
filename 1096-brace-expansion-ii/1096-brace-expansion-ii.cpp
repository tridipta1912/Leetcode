class Solution
{
public:
    set<string> parse(string& s, int& i)
    {
        set<string> res, cur;

        while (i < s.size() && s[i] != '}')
        {
            if (s[i] == ',')
            {
                res.insert(cur.begin(), cur.end());
                cur.clear();
                i++;
            }
            else
            {
                set<string> part;

                if (s[i] == '{')
                {
                    i++;
                    part = parse(s, i);
                    i++;
                }
                else
                {
                    part.insert(string(1, s[i]));
                    i++;
                }

                if (cur.empty())
                    cur = part;
                else
                {
                    set<string> next;

                    for (auto& a : cur)
                        for (auto& b : part)
                            next.insert(a + b);

                    cur = move(next);
                }
            }
        }

        res.insert(cur.begin(), cur.end());
        return res;
    }

    vector<string> braceExpansionII(string expression)
    {
        int i = 0;
        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};