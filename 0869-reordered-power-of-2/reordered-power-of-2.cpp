class Solution {
public:
    bool reorderedPowerOf2(int n) {
        using ll = long long;
        vector<ll> arr;
        vector<ll> freq(10);
        while(n)
        {
            freq[n % 10]++;
            n /= 10;
        }
        for(ll i = 1; i <= 1e10; i *= 2)
        {
            vector<ll> freq1(10);
            ll tt = i;
            while(tt)
            {
                freq1[tt % 10]++;
                tt /= 10;
            }
            if(freq == freq1)   return true;
        }
        return false;
    }
};