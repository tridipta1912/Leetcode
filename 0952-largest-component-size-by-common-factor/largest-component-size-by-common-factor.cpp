class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        unordered_map<int, vector<int>> chc;

        function<vector<int>(int)> getFactors = [&](int x)
        {
            if (chc.count(x)) return chc[x];

            int orig = x;
            vector<int> res;
            for (int d = 2; d * d <= x; d++)
            {
                if (x % d == 0)
                {
                    res.push_back(d);
                    while (x % d == 0) x /= d;
                }
            }
            if (x > 1) res.push_back(x);
            return chc[orig] = res;
        };

        unordered_map<int, int> parent;

        function<int(int)> find = [&](int x)
        {
            if (!parent.count(x)) parent[x] = x;
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

        auto unite = [&](int u, int v)
        {
            u = find(u);
            v = find(v);
            if (u != v) parent[v] = u;
        };

        for (int num : nums)
        {
            auto pf = getFactors(num);
            if(pf.empty())  continue;
            for (int i = 1; i < pf.size(); i++)
                unite(pf[0], pf[i]);
        }

        unordered_map<int, int> freq;
        int ans = 0;

        for (int num : nums)
        {
            auto pf = getFactors(num);
            if(pf.empty())  continue;
            int root = find(pf[0]);
            ans = max(ans, ++freq[root]);
        }

        return ans;
    }
};
