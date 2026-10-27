class Solution {
public:
struct DSU
{
    vector<int> p, r;
    
    DSU(int n)
        : p(n), r(n, 0)
    {
        iota(p.begin(), p.end(), 0);
    }
    
    int find(int x)
    {
        return p[x] == x ? x : (p[x] = find(p[x]));
    }
    
    bool join(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
        return true;
    }
};

int solve(int n, vector<vector<int>>& e, int k)
{
    vector<int> vals;
    for (auto &x : e)
    {
        vals.push_back(x[2]);
        if (x[3] == 0)
            vals.push_back(2 * x[2]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    auto ok = [&](int x)
    {
        DSU d(n);
        int cnt = 0;
        for (auto &a : e)
        {
            if (a[3] == 1)
            {
                if (a[2] < x)
                    return false;
                if (!d.join(a[0], a[1]))
                    return false;
                cnt++;
            }
        }
        if (cnt > n - 1)
            return false;

        int comps = 0;
        for (int i = 0; i < n; i++)
        {
            if (d.find(i) == i)
                comps++;
        }

        vector<tuple<int, int, int>> opt;
        for (auto &a : e)
        {
            if (a[3] == 0)
            {
                if (a[2] >= x)
                    opt.push_back({0, a[0], a[1]});
                else if (2 * a[2] >= x)
                    opt.push_back({1, a[0], a[1]});
            }
        }
        sort(opt.begin(), opt.end());

        int used = 0;
        for (auto &[c, u, v] : opt)
        {
            if (comps == 1)
                break;
            if (d.join(u, v))
            {
                comps--;
                if (c == 1 && ++used > k)
                    return false;
            }
        }
        return comps == 1;
    };

    int l = 0, r = (int)vals.size() - 1, ans = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ok(vals[m]))
        {
            ans = vals[m];
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return ans;
}

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        return solve(n, edges, k);
    }
};