using ll = long long;
constexpr ll MOD = 1e9 + 7;
constexpr ll N = 1000;

vector<ll> fact(N + 1), invFact(N + 1);

class Solution
{
public:
    Solution()
    {
        fact[0] = 1;

        for(ll i = 1; i <= N; i++)
        {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invFact[N] = binpow(fact[N], MOD - 2);

        for(ll i = N; i >= 1; i--)
        {
            invFact[i - 1] = invFact[i] * i % MOD;
        }
    }

    ll binpow(ll a, ll b)
    {
        ll ans = 1;

        while(b)
        {
            if(b & 1)   ans = ans * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }

        return ans;
    }

    ll nCr(ll n, ll r)
    {
        return fact[n] * invFact[r] % MOD
             * invFact[n - r] % MOD;
    }

    ll solve(vector<int>& nums)
    {
        if(nums.size() <= 2)    return 1;

        ll n = nums.size();
        vector<int> left, right;

        for(ll i = 1; i < n; i++)
        {
            if(nums[i] < nums[0])   left.push_back(nums[i]);
            else                    right.push_back(nums[i]);
        }

        ll L = left.size();
        ll R = right.size();

        ll ans = nCr(L + R, L);
        ans *= solve(left), ans %= MOD;
        ans *= solve(right), ans %= MOD;

        return ans;
    }

    int numOfWays(vector<int>& nums)
    {
        ll ans = solve(nums);
        return ((ans - 1) % MOD + MOD) % MOD;
    }
};