class Solution
{
public:
    int sumCounts(vector<int>& nums)
    {
        using ll = long long;
        const ll MOD = 1'000'000'007;

        int n = nums.size();
        vector<ll> sum(4 * n), sq(4 * n), lazy(4 * n);
        vector<int> last(100001, -1);

        auto apply = [&](auto&& self, int node, int l, int r, ll v) -> void
        {
            ll len = r - l + 1;

            sq[node] = (sq[node] + 2 * v % MOD * sum[node] % MOD
                        + len * v % MOD * v % MOD) % MOD;

            sum[node] = (sum[node] + len * v) % MOD;
            lazy[node] = (lazy[node] + v) % MOD;
        };

        auto push = [&](auto&& self, int node, int l, int r) -> void
        {
            if (lazy[node] == 0 || l == r)
            {
                return;
            }

            int mid = (l + r) / 2;

            apply(apply, node * 2, l, mid, lazy[node]);
            apply(apply, node * 2 + 1, mid + 1, r, lazy[node]);

            lazy[node] = 0;
        };

        auto update = [&](auto&& self, int node, int l, int r, int ql, int qr) -> void
        {
            if (ql <= l && r <= qr)
            {
                apply(apply, node, l, r, 1);
                return;
            }

            push(push, node, l, r);

            int mid = (l + r) / 2;

            if (ql <= mid)
            {
                self(self, node * 2, l, mid, ql, qr);
            }

            if (qr > mid)
            {
                self(self, node * 2 + 1, mid + 1, r, ql, qr);
            }

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        auto query = [&](auto&& self, int node, int l, int r, int ql, int qr) -> ll
        {
            if (ql <= l && r <= qr)
            {
                return sq[node];
            }

            push(push, node, l, r);

            int mid = (l + r) / 2;
            ll res = 0;

            if (ql <= mid)
            {
                res = (res + self(self, node * 2, l, mid, ql, qr)) % MOD;
            }

            if (qr > mid)
            {
                res = (res + self(self, node * 2 + 1, mid + 1, r, ql, qr)) % MOD;
            }

            return res;
        };

        ll ans = 0;

        for (int r = 0; r < n; r++)
        {
            int p = last[nums[r]];

            update(update, 1, 0, n - 1, p + 1, r);

            ans = (ans + query(query, 1, 0, n - 1, 0, r)) % MOD;

            last[nums[r]] = r;
        }

        return ans;
    }
};