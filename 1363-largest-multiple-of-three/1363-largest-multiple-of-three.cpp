class Solution
{
public:
    string largestMultipleOfThree(vector<int>& digits)
    {
        vector<vector<int>> dig(3);
        int sum = 0;
        
        for (auto x : digits)
        {
            dig[x % 3].push_back(x);
            sum += x;
        }

        for (int i = 0; i < 3; ++i)
        {
            sort(dig[i].rbegin(), dig[i].rend());
        }

        auto remove = [&](int m, int cnt)
        {
            if (dig[m].size() >= cnt)
            {
                while (cnt--)
                {
                    dig[m].pop_back();
                }
                return true;
            }
            return false;
        };

        if (sum % 3 == 1)
        {
            if (!remove(1, 1))
            {
                remove(2, 2);
            }
        }
        else if (sum % 3 == 2)
        {
            if (!remove(2, 1))
            {
                remove(1, 2);
            }
        }

        string s = "";
        for (int i = 0; i < 3; ++i)
        {
            for (int x : dig[i])
            {
                s += to_string(x);
            }
        }

        sort(s.rbegin(), s.rend());

        if (!s.empty() && s[0] == '0')
        {
            return "0";
        }

        return s;
    }
};
