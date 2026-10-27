class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        using ll = long long;
        vector<ll> parents(n);
            for(int i = 0; i < n; i++)parents[i] = i;
        vector<ll> sizes(n, 1LL);
        ll conn = n;

        function<int(int)> par = [&](ll x)
        {
            return (parents[x] = ((parents[x] == x) ? x : par(parents[x])));
        };

        auto connect = [&](ll x, ll y)
        {
            ll px = par(x);
            ll py = par(y);

            if(px == py)return false;

                if(sizes[x] < sizes[y])swap(x, y);

            sizes[x] += sizes[y];
            parents[par(y)] = par(x);
            return true;
        };

        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b)
             {
                 return (a[2] < b[2]);
             });

        for(auto nums : edges)
            {
                if(connect(nums[0], nums[1]))
                   {
                        conn--;
                   }
                if(conn == k)
                {
                    return nums[2];
                }
            }
        return 0;
    }
};