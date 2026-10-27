class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        using ll = long long;
        ll cnt = 0;

        auto check = [&](ll x)
        {
            if(x & 1)   return false;
            vector<ll> freq(10);
            for(auto x : digits)freq[x]++;
            while(x)
            {
                if(freq[x % 10] == 0)   return false;
                freq[x % 10]--;
                x /= 10;
            }
            return true;
        };

        for(ll i = 100; i <= 999; i++)  cnt += check(i);
        return cnt;
    }
};