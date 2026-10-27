class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        using ll = int;
        vector<ll> divisors;
        ll n = nums.size();
        for(ll i = 1; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                divisors.push_back(i);
                if(i * i != n)  divisors.push_back(n / i);
            }
        }
        ll ans = 0;
        for(auto x : divisors)
        {
            ll partitions = (n / x);
            vector<ll> cyc(partitions, -1);
            bool is_asc = true;
            for(ll i = 0; i + 1 < n; i++)
            {
                if(nums[i] > nums[i + 1])
                {
                    ll A = (i / x);
                    ll B = ((i + 1) / x);
                    if(A == B)
                    {
                        if(cyc[A] == -1)  cyc[A] = x - (i % x) - 1;
                        else
                        {
                            is_asc = false;
                        }
                    }
                }
            }
            vector<ll> arr(nums.begin(), nums.end());
            for(ll i = 0; i < n; i++)
            {
                ll part = (i / x);
                
                if(cyc[part] != -1)
                {
                    arr[part * x + (i + cyc[part]) % x] = nums[i];
                } 
            }
            for(ll i = 1; i < n; i++)   if(arr[i] < arr[i - 1]) is_asc = false;
            if(is_asc)  ans += x;
        }

        return ans;
    }
};