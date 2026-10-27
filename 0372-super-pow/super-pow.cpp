#include <vector>
using namespace std;

class Solution {
public:
    #define ll long long int
    const ll MOD = 1337;

    ll phi(ll n) {
        ll result = n;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        }

        if (n > 1)
            result -= result / n;

        return result;
    }

    ll binpow(ll a, ll b) 
    {
        a %= MOD;   
        ll res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        ll MO = phi(1337);
        ll k = 0;
        for (auto nums : b) {
            k = ((k * 10) % MO + nums) % MO;
        }
        if(k == 0)    k = MO;
        ll f = a % MOD;
        ll ans = binpow(f, k);
        int an = ans;
        return an;
    }
};
