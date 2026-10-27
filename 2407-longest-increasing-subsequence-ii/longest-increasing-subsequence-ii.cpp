using ll = long long;
struct Segtree
{
    vector<ll> T;
    Segtree (ll n)
    {
        T.assign(4 * n, 0);
    }
    void update(ll v, ll l, ll r, ll idx, ll val)
    {
        if(l == r)
        {
            T[v] = max(T[v], val);
            return;
        }
        ll m = (l + r) / 2;
        if(idx <= m)    update(2 * v, l, m, idx, val);
        else            update(2 * v + 1, m + 1, r, idx, val);
        T[v] = max(T[2 * v], T[2 * v + 1]);
    }
    ll query(ll v, ll l, ll r, ll ql, ll qr)
    {
        if(l >= ql && r <= qr)  return T[v];
        if(l > qr || r < ql)    return 0;
        ll m = (l + r) / 2;
        return max(query(2 * v, l, m, ql, qr), query(2 * v + 1, m + 1, r, ql, qr));
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        ll n = nums.size();
        ll M = *max_element(nums.begin(), nums.end());
        Segtree st(M + 1);
        for(ll i = 0; i < n; i++)
        {
            ll L = max(0LL, (ll)nums[i] - k);
            ll R = max(0LL, (ll)nums[i] - 1);
            ll maxx = (st.query(1, 0, M, L, R)) + 1;
            st.update(1, 0, M, nums[i], maxx);
        }
        return st.query(1, 0, M, 0, M);
    }
};