#include<bits/stdc++.h>
using ll = long long;
const ll MOD = 1e9 + 7;
ll N = 5e5 + 5;  

ll extgcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    ll x1 = 0, y1 = 1;
    while (b) {
        ll q = a / b;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a, b) = make_tuple(b, a - q * b);
    }
    return a;
}

struct mint {
    ll x;
    mint() : x(0) {}
    mint(ll y) {
        x = y % MOD;
        if (x < 0) x += MOD;
    }

    mint operator-() const { return mint(-x); }
    mint operator~() const { ll a, b; extgcd(x, MOD, a, b); return mint(a); }

    mint& operator+=(const mint& a) { x += a.x; if (x >= MOD) x -= MOD; return *this; }
    mint& operator-=(const mint& a) { x -= a.x; if (x < 0) x += MOD; return *this; }
    mint& operator*=(const mint& a) { x = (x * a.x) % MOD; return *this; }
    mint& operator/=(const mint& a) { return *this *= ~a; }

    mint pow(ll b) const {
        mint res = 1, a = *this;
        while (b > 0) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }

    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }

    friend istream& operator>>(istream& is, mint& m) { ll y; is >> y; m = mint(y); return is; }
    friend ostream& operator<<(ostream& os, const mint& m) { return os << m.x; }

    bool operator<(const mint& a) const { return x < a.x; }
    bool operator>(const mint& a) const { return x > a.x; }
    bool operator==(const mint& a) const { return x == a.x; }
    bool operator!=(const mint& a) const { return x != a.x; }
};

vector<mint> fact(N), invfact(N);

void initiate() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i;

    invfact[N - 1] = ~fact[N - 1];
    for (int i = N - 2; i >= 0; --i)
        invfact[i] = invfact[i + 1] * (i + 1);
}

mint C(ll n, ll r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return fact[n] * invfact[r] * invfact[n - r];
}

class Solution {
public:
    int countValidSequences(int n, int k) {
        N = n + 1;
        initiate();
        mint ans = C(n - 1, k - 1);
        if((n + k) % 2 == 0) ans -= C((n + k) / 2 - 1, k - 1);
        return ans.x;
    }
};